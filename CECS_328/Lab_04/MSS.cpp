#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <algorithm> // partition
using namespace std;

int MSS(int a[], int NUMELEMS);
void printArray(int a[], int NUMELEMS);

int main()
{
  int n = 0;
  int k = 0;
  double average = 0;
  cout << "Please enter an integer: ";
  cin >> n;
  int *a = new int[n];
  srand(time(NULL));
  for(int j = 0; j < n; j++)
    a[j] = rand()%201 + (-100); // randomize array [-7000,7000]
  auto start = std::chrono::steady_clock::now();
  cout << "The MSS is " << MSS(a, n) << endl;
  auto end = std::chrono::steady_clock::now();
  average += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  printArray(a, n);
  printf("MSS took: %.2f ns on average\n", average);
  return 0;
}

int MSS(int a[], int NUMELEMS)
{
  int maxSum = 0;
  int temp = 0;
  for(int i = 0; i < NUMELEMS; i++)
  {
    temp += a[i];
    if(temp > maxSum)
      maxSum = temp;
    if(temp < 0)
      temp = 0;
  }
  return maxSum;
}

void printArray(int a[], int NUMELEMS)
{
  for(int i = 0; i < NUMELEMS; i++)
    printf("\t%d\n", a[i]);
}
