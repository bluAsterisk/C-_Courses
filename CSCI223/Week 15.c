#include <stdio.h>

// Conditional Compilation
// _______________________
// * Use preprocessor #defines to control what compiler sees.
// ex:
#define FALL
#if defined(SPRING)
puts("SPRING");
#elif defined(FALL)
puts("FALL");
#else
puts("VACATION");
#endif
// the compiler only sees puts("FALL")

// * If values are associated wih symbols, relational operators can be used:
// ex:
#define FALL 2016
#if FALL > 2016
puts("Future");
#elif FALL < 2016
puts("Past");
#else
puts("Present");
#endif // FALL

// * Can also use logical opterators:
// ex:
#if defined(fall) || defined(SPRING)
puts ("School!");
#else
puts("Vacation")
#endif

// * Can be useful in a variety of situations:
//  - Multiple OSs:
#ifdef WIN32; // WIN32
#else //MAC
#endif
// - Debug Versions
#ifdef Debug
#endif
// - Can enable/disable clocks of code
#if 1
#endif
// can #define symbols from command line:
// gcc -D DEBUG foo.c
// Or, #undef a sympul:
// gcc -U DEBUG foo.c



// Guarding Against Nested Includes
// ________________________________
// ex:
// foo1.h
#ifndef FOO1_HDR
#define FOO1_HDR

struct foo1
{
  //
};
// foo1.c
#include "foo1.h"

// foo2.h
#ifndef FOO2_HDR
#define FOO2_HDR

#include "foo1.h"
struct foo2
{
  struct Foo1 foo1;
};

// foo2.c
#include "foo1.h"
#include "foo2.h"

// gcc -c foo1.c
// foo1.c -> preprocessor -> foo1.i -> gcc -> foo1.o

// gcc -c foo2.c
// foo2.c -> preprocessor -> foo2.i



// Variable-Length Argument Lists
// ______________________________
// The folloWINg macro allows args to be aligned on integer boundary on stack
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
// ex:
// sizeof(n) -> 6 bytes
// The sizes in the first expression is bitwise AND with the second
// So 9 & ~3 = 8

// Sets pointer to point to 1st optional argument
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - INTSIZEOF(t)))
// Note: In C, arguments are pushed on the stack in reverse order.


// ANSI Macros (p.1078)
// __DATE__ -> "May 12 2016"
// __FILE__ -> "foo.c"
// __LINE__ -> the current line number (int)
// __TIME__ -> "16:32:05" (time of build)
// __TIMESTAMP__ -> "Thursday May 12 16:32:05 2016"


// vprintf Functions
// _________________
int vprintf(const char *format, va_list argPtr);
int vfprintf(FILE *stream, const char *format va_list argPtr);
int vsprintf(char *str, const char *format, va_list argPtr);

// main
fptr = fopen ("err.log", "a");
LogMesg(fptr, "Foo: %s at line %d -- intVal = %d\n",
                                            __FILE__,
                                            __LINE__,
                                            intVal);
void LogMesg(FILE *logFile, char *format, ...)
{
  auto va_list argPtr; // char*
  va_start(argPtr, format);
  vfprintf(stderr, format, argPtr);
  va_start(argPtr, format);
  vfprintf(logFile, format, argPtr);
  va_end(argPtr);
  if(fflush(logFile)) // good practice to flush stdout
  {
    fprintf(stderr, "Log Mesg: fflush failed!\n");
  }
}


// Mapping Function Identifiers
// ____________________________
// * Assume "FooWIN" and "FooMac" exist for those OS's,
//   and you have a single code base:
//  A)
// statement;
#ifndef WIN
FooWIN(arg1, arg2);
#else
FooMac(arg1, arg2);
#endif
// more statements;

// B)
#ifdef WIN
#define Foo FooWIN
#else
#define Foo FooMac
#endif

// some statements;
Foo(arg1, arg2) // --> FooWIN(arg1, arg2)
// more statements;



// GDB Debugging
// _____________
// * To build with debug information, use the -g switch
// * To view source: use the "list"
// * Toggle "tui" mode: ctrl + x, a
// * Toe execute a line of code: nex or 'n'
// * To refresh tui display:
//    - toggle into command line and back
//    - or ctrl + l



// Posix Threads
// _____________
#include <pthread.h>
// * A process has the folloWINg:
//    - a process ID (PID)
//    - a stack
//    - a set of registers
//    - memory
//    - file descriptors
// * A thread has:
//    - thread ID
//    - stack
//    - registers
// * A thread will share the process' global memory
//   and file descriptors
// Note: Be sure to link with the library:
// ex: gcc -l pthread foo.c

// What to do:
// ___________
// * Declare a variable of type pthread_t.
//   This will store the thread ID.
// * Call pthread_create:     pass NULL for default  vvv
int pthread_create(pthread_t *thread, pthread_attr_t *attr,
                    void *(*start)(void*), void *arg);
                    // arg gets forwarded to void*



// Sockets
// _______
// * Allow 2-way communication between processes.
//  - can be on he same machine, or across a network.
// * Two primary protocols:
//  1) UDP("User Datagram Protocol")
//    - transmits data in chunks called "datagrams"
//    - unrealiable, connectionless
//    - packets may arrive in different order, or not at all
//  2) TCP ("Transmission Control Protocol")
//    - reliable, connection-oriented
//    - stream of bytes



// Socket Connections
// __________________
//  ________    ________
// | CLIENT |  | SERVER |
//  --------    --------
//      |           |
//   socket()    socket()
//      |           |
//      |         bind()
//      |           |
//      |        listen()
//      |           |
//      |        accept() <- [blacking call...]
//      |           |
//   connect()      |
// ______________________



// * Creating a socket: socket()
//   ___________________________
//  - domain
//    - AF_UNIX for Unix sockets
//    - AF_INET for network
//  - type
//    - SOCK_DGRAM (UDP) or SOCK_STREAM (TCP)
//  - protocol
//    - use zero for default
//  - returns socket descriptor, or -1 on failure

// * bind()
//   ______
// - binds socket to an address
// - returns 0 on success, -1 on failure
// - 2nd parameter takes ponter to struct:
struct sockaddr
{
  unsigned short sa_family;
  char sa_data[14];
  // Byte compatible with
  // sockaddr_un
  // sockaddr_in
};

// * listen()
//   ________
// - returns zero on success, -1 on failure
// - "backlog" is size of pending connections queue (5 is typical)

// * accept()
//   ________
// - acceps incoming connection
// - can pass NULL pointers if you don't want client info
// - returns a new socket descriptor that represents connection
//   with the client

// * connect()
//   _________
// - client connects to server



// Network Sockets
// _______________
// * Send/receive data on same machine or across a network
// * Addresses use IP address and a port number
//  - IP address specifies host machine
//  - port number specifies target application
// * Ranges of port numbers:
//  - 0 to 1023 reserved for superuser
//  - 1024 to 49151 reserved for applications
//  - 49152 to 65535 are unreserved for temp transient connections
// *
struct sockaddr.in
{
  short int sin_family; // AF_INET
  unsigned short sin_port; // port number
  struct in_address // stores IP address
//                    ^--- has one member: /s_adder
};



// Litte Endian vs. Big Endian
// ___________________________
// * How is the 4-byte int stored (ex: ox12345678)
// Big Endian (Network Byte Order) Little Endian
//    | 12 |                        | 78 |
//    | 34 |                        | 56 |
//    | 56 |                        | 34 |
//    | 78 |                        | 12 |



// Functions to Produce Network-Byte-Order:
// ________________________________________
// htonl and htons => ("host to network long/short")
// ntohl and ntohs => ("network to host long/short")
// ex: myShort = htons(myShort);



// IP Addresses
// ____________
// * Server:
//    - .sin_addr.s_addr = htonl(INADDR_ANY);
// * Client:
//    - .sin_addr.s_addr = htonl(INADDR_LOOPBACK);
// Note: IP address of local host is 127.0.0.1
//      ("home address" or "loopback address")
// * If you want to use a string IP:
int inet_aton(const char *strIP, struct in_addr *inp);
