#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

long HailstoneSequence(long n);

int main(){
	int qid = msgget(
	        ftok(".",'u'),
	        IPC_EXCL | IPC_CREAT | 0600
	        );
    if( qid < 0 ){
      cout << "Challenger, Q create fail!\n";
	    qid = msgget(
	        ftok(".",'u'),
	        IPC_EXCL | 0600
	        );
      if( qid < 0 ){
        cout << "Challenger, Q access fail!\n";
        exit( -1 );
        }
		else
			cout << "Q create SUCCESS\n";

	struct buf {
		long mtype;
		char g[5];
	};
	buf msg;
	int size = sizeof(msg)-sizeof(long);
	do{
			if( msg.mtype < 0 ) break;
			msg.mtype = 0;
			msgrcv( qid,    // RECEIVE
							(struct msgbuf *)&msg,
							size,
							msg.mtype,
							0);
			cout << "Checking queue...\n";
			cout    << "Challenger,Received: "
								<< msg.mtype
								<< endl;
			if(msg.mtype == 1)
				break;
			msg.mtype = HailstoneSequence(msg.mtype);
			cout    << "Challenger,Sending: "
							<< msg.mtype
							<< endl;
			if(
					msgsnd( qid,
					(struct msgbuf *)&msg,
					size,
					0 )
					< 0 ){
					cout << "Challenger, send FAIL!\n";
			}
	}while( msg.mtype > 0 );
	cout << "Challenger, Removing Q\n";
	if( msgctl (qid, IPC_RMID, NULL) )
	    cout << "Challenger, Q remove FAIL!\n";
    else
	    cout << "Challenger, Q remove SUCCESS!\n";
	exit(0);
	}
}

long HailstoneSequence(long n)
{
  long nextVal;
  bool odd;
  if(n % 2)
    odd = true;

  if(odd) // odd
  {
    nextVal = (3 * n) + 1; // (n + 1) = 3 * (n + 1)
    return nextVal;
  }
  else      // even
  {
    nextVal = n / 2;
    return nextVal; // (n + 1) = n / 2
  }
}
