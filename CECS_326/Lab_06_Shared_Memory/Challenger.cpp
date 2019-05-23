#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>

#include <time.h>

#include <iostream>
using namespace std;

short HailstoneSequence(short n);
// compile with: g++ readerOfInts.cpp -o 1_reader.out -lrt

int main(){

	const int SIZE = 128;
	const char *name = "Challenge";
	// open shared memory region named "Challenge"
	int shm_fd;
	void *ptr;
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	// shm_fd = shm_open(name, O_RDWR, 0666);

	if(shm_fd == -1){
		cout << "1: ERROR: Opening shared memory failed\n";
		exit(-1);
	}

	ftruncate(shm_fd, SIZE);
	/*void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);	*/
	ptr = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
	if(ptr == MAP_FAILED){
		cout << "1: ERROR: Map failed\n";
		exit(-1);
	}
  //do{
    // cout << "Input a numerical positive short integer value to send to shared memory: ";
    short x;
    //cout << "1: Value to write into shared memory: ";
    //cin >> x;
		//*((short *)ptr) = x;
  //   if( x < 0 ){
  //     cout << "Negative value encountered, exiting!\n";
  //     break;
  //   }
  //
  // }while( 1 );
	// short newValue = 0;
	// short value = *((short *)ptr);
	do{
		// bool oldData = true;
		// while( oldData ){
		// 	newValue = *((short *)ptr);
		// 	if( newValue != value )
		// 		oldData = false;
		// }	// end of while( oldData )
		x = *((short *)ptr); // read shared memory region
		cout << "1: Value to write into shared memory: " << x << endl;
		cout << "1: Awaiting new data in shared memory region\n";
		x = HailstoneSequence(x);
		*((short *)ptr) = x; // write memory
		x = *((short *)ptr); // read shared memory region
		cout << "1: Value Received: " << x << endl;
    if(x == 1) // already lost
    {
      cout << "1: I lose!\n";
      x = -1;
			break;
    }
    else if(x == 2) // (n + 1) will be 1 next
    {
      cout << "VICTORY IS MINE!\n\nI WIN!\n\n";
			x = HailstoneSequence(x);
			*((short *)ptr) = x; // write memory
      x = -1;
			break;
    }
	}while( x > 0 );

	cout << "1: Attempting to close the shared memory region\n";

	if(shm_unlink(name) == -1){
		cout << "1: ERROR: Error removing shared memory region" << name << endl;
		exit(-1);
	}
	else
		cout << "1: Successfully closed shared memory region" << endl;
	return 0;
}

short HailstoneSequence(short n)
{
  short nextVal;
  bool odd;
  if(n % 2)
    odd = true;

  if(odd) // odd
  {
    nextVal = (3 * n) + 1; // (n + 1) = (3 * n) + 1)
    return nextVal;
  }
  else      // even
  {
    nextVal = n / 2;
    return nextVal; // (n + 1) = n / 2
  }
}
