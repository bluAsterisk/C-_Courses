#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <time.h>

using namespace std;

// Thread Management Global Declarations

// Pthread variables
// array of worker thread IDs
pthread_t *tids;
// Enable a worker thread to print
// worker thread pringting complete
pthread_cond_t *tEnable, tPrinted;
// mutex variable
pthread_mutex_t theMutex;

static int cleanup_pop_arg = 0;
static void cleanupHandler(void *arg){
	cout << "Worker " << cleanup_pop_arg
		 << " cleaning up and exiting\n"
		 << "Worker ";

	if(pthread_mutex_unlock(&theMutex) != 0)
		cout << "UHOH!\n";
}

// thread launch delay variable
short signify = 0;

// Worker Info Management Class
// Class for Worker Thread data

class WorkerInfo{
public:
	WorkerInfo(){}

	WorkerInfo( WorkerInfo &wi)
		:workerID( wi.workerID ),
		sizeOfDataSet( wi.sizeOfDataSet ){
		dataSet = new short[ sizeOfDataSet];
		for( int i = 0; i < sizeOfDataSet; i++ )
			dataSet[i] = wi.dataSet[i];
	}

	WorkerInfo (short wid, short sods)
		:workerID( wid ), sizeOfDataSet( sods ){}

	void putDataInSet(short sA[], short size){
		if(size != sizeOfDataSet){
			cout << "\tsizes not equal\n";
			sizeOfDataSet = size;
			if( dataSet != NULL )
				delete [] dataSet;
			dataSet = new short[size];
		}
		if( dataSet == NULL ){
			cout << "Allocating memory for data set!\n";
			dataSet = new short[size];
		}
		cout << "\tinitializing dataset\n";
		for( int i = 0; i < sizeOfDataSet; i++)
			dataSet[ i ] = sA[ i ];
	}

	void showDataSet(){
		cout << "worker " << workerID << " showing data: \n";
		for( int i = 0; i < sizeOfDataSet; i++)
			cout << '\t' << dataSet[ i ] << endl;
	}

	short getWorkerID(){ return workerID;}

	~WorkerInfo(){
		cout << workerID << " destroying data set\n\n";
		delete [] dataSet;
	}

private:
	short workerID = 0;
	short sizeOfDataSet = 0;
	short *dataSet = NULL;
};

// workder controller thread function
void *boss( void *param ){
	short runningWorkers = *((short *) param);
	bool workerRunning[*(short *) param];
	int input;
	int i = 0;
	while(i < *(short *)param)
	{
		workerRunning[i] = true;
		i++;
	}
	cout << "!!! boss Thread Running!\n" << "managing "
		<< *(short *)param << " worker threads\n";
	cout << "Enter a number of 1 to " << *(short *)param << " "
		<< "to make a thread print it's data set\n"
		<< "Enter the negated value of a worker thread to cancel that thread\n"
		<< "Enter 0 to make all threads out put their data sets\n";
	do{ // loop 1
		cin >> input;
		if(input == 0)
		{
			i = 0;
			while(i < *(short *)param) // loop 2
			{
				if(workerRunning)
					pthread_cond_signal(&tEnable[i]);
				i++;
			}
		}
		if(input > 0 && input <= *(short *)param)
		{
			if(workerRunning[input -1])
				pthread_cond_signal(&tEnable[input - 1]);
			else
				cout << "worker " << input << " already finished\n";
		}
		if(input < 0 && (-input) <= *(short *)param)
		{
			input = -input;
			if(workerRunning[input -1])
				{
					cout << "Canceling worker " << input << endl;
					cleanup_pop_arg = input;
					pthread_cancel(tids[input-1]);
					workerRunning[input - 1] = false;
					runningWorkers--;
				}
			else
				cout << "Worker " << input << " already canceled\n";
		}
		//else
		//	cout << "ERROR: Invalid Entry\n";
	}while(runningWorkers > 0);
	cout << "BOSS exits! \n";
	pthread_exit(0);
};

// worker thread function
void *worker( void *param )
{
	WorkerInfo myInfo(*(WorkerInfo *)param);
	cout << "Worker Thread " << myInfo.getWorkerID() << " Running!\n";
	signify++;
	pthread_cleanup_push(cleanupHandler, NULL);
	while(1)
	{
		pthread_mutex_lock(&theMutex);
		pthread_cond_wait(&tEnable[myInfo.getWorkerID() - 1], &theMutex);
		myInfo.showDataSet();
		pthread_mutex_unlock(&theMutex);
	}
	pthread_cleanup_pop(cleanup_pop_arg);
};

// main function

int main( int argc, char ** argv){
	short numThreads = atoi( argv[1] ); // number of workers to be created
	tids = new pthread_t[ numThreads ];
	tEnable = new pthread_cond_t[ numThreads ];
	pthread_t bossTid;
	pthread_mutex_init( &theMutex, 0);
	short dataSetIndex = 2;
	for( int i = 0; i < numThreads; i++){
		short sizeOfDataSet = atoi( argv[dataSetIndex]);
		WorkerInfo tempWorker( i + 1, sizeOfDataSet);
		cout << "Temp workder"
			 << tempWorker.getWorkerID()
			 << " initializing! \n";
		short dSet[sizeOfDataSet];
		dataSetIndex++;
		for( int j = 0;
			 j < sizeOfDataSet;
			 ++j){
			dSet[ j ] = atoi( argv[ dataSetIndex] );
			cout << "dSet[ " << j << " ] = " << dSet[j] << endl;
			dataSetIndex++;
		}
		cout << "sizeof dset: "
			 << (sizeof(dSet) / sizeof(short) )
			 << endl;
		tempWorker.putDataInSet( dSet, sizeOfDataSet);
		pthread_cond_init( &tEnable[i], 0);
		cout << "Creating worker thread\n";
		short temp = signify;
		pthread_create(&tids[i], NULL, worker, &tempWorker);
		// wait for thread to launch / initialize
		while( signify == temp);
		cout << "temp worker";
	}
	pthread_create( &bossTid, NULL, boss, &numThreads);
	cout << "Main thread blocking until boss thread finishes\n\n";
	pthread_join( bossTid, NULL);
	cout << "\n\nMain thread unblocked and outta here \n\n";
	for( int i = 0; i < numThreads; i++)
		pthread_cond_destroy( &tEnable[i] );
	pthread_mutex_destroy( &theMutex );
	// dellocate heap memory
	delete [] tids;
	// dellocate heap memory
	delete [] tEnable;
}
