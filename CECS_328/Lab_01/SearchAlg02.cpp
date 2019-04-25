#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#define mid L + ((R - L)/2)
using namespace std;

double LinearSearch(int array[], int NUMELEMS, int k);
double BinarySearch(int L, int R, int array[], int NUMELEMS, int k);

int main()
{
  int n = 0;
  int key = 0;
  cout << "Please enter an integer\n";
  cin >> n;
  int * SearchArray = new int [n];
  // loading array with random integers
  for(int i = 0; i < n; i++)
  {
    srand(time(NULL));
    SearchArray[i] = rand()%1000;
  }
  key = 5000;
  sort(SearchArray, SearchArray + n);
  printf("Linear search takes %.2fns \n", (LinearSearch(SearchArray, n, key)/n));
  printf("Binary search takes %.2fns \n", BinarySearch(0, n, SearchArray, n, key));
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
    auto end = std::chrono::steady_clock::now();
  // check mid
  else if(k == array[mid])
  //  auto end = std::chrono::steady_clock::now();
  // check left
  else if(k < array[mid])
    BinarySearch(L, mid - 1, array, NUMELEMS, k);
  // check right
  else
    BinarySearch(mid + 1, R, array, NUMELEMS, k);
  //auto end = std::chrono::steady_clock::now();
  return double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
}
