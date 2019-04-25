#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#define mid L + ((R - L)/2)
#define endCount 500
using namespace std;

double LinearSearch(int array[], int NUMELEMS, int k);
double BinarySearch(int L, int R, int array[], int NUMELEMS, int k);

int main()
{
  int n = 0;
  int key = 0;
  cout << "Please enter an integer\n";
  cin >> n;
  int SearchArray[n];
  double avgTime = 0;
  // loading array with random integers
  for(int i = 0; i < n; i++)
  {
    srand(time(NULL));
    SearchArray[i] = rand()%1000;
  }
  sort(SearchArray, SearchArray + n);

  // Linear Search
  for(int count = 0; count < endCount; count++){
  srand(time(NULL));
  key = rand()%1000;
  auto start = std::chrono::steady_clock::now();
  avgTime += LinearSearch(SearchArray, n, key);
  auto end = std::chrono::steady_clock::now();
  }
  printf("Linear search takes %.2fns on average\n", avgTime / endCount);

  // Binary Search
  avgTime = 0; // reset
  for(int count = 0; count < endCount; count++){
  srand(time(NULL));
  key = rand()%1000;
  auto start = std::chrono::steady_clock::now();
  avgTime += BinarySearch(0, n, SearchArray, n, key);
  auto end = std::chrono::steady_clock::now();
  }
  printf("Binary search takes %.2fns  on average\n", avgTime / endCount);
  return 0;
}

double LinearSearch(int array[], int NUMELEMS, int k)
{
  auto start = std::chrono::steady_clock::now();
  for(int i = 0; i < NUMELEMS; i++)
  {
    if(k == array[i])
    break;
  }
  auto end = std::chrono::steady_clock::now();
  return double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
}

double BinarySearch(int L, int R, int array[], int NUMELEMS, int k)
{
  auto start = std::chrono::steady_clock::now();
  // if not found
  if(L == 0 || R == 0)
    return array[0];
  // check mid
  if(k == array[mid])
    return (R - L) / 2;
  // check left
  else if(k < array[mid])
    BinarySearch(L, mid - 1, array, NUMELEMS, k);
  // check right
  else
    BinarySearch(mid + 1, R, array, NUMELEMS, k);
  auto end = std::chrono::steady_clock::now();
  return double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
}
