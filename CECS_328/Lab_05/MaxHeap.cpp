#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <algorithm> // partition
using namespace std;

#define REPS 100
void heap_sort(int a[], int NUMELEMS);
void build_MaxHeap(int a[], int NUMELEMS);
void max_heapify(int a[], int NUMELEMS, int index);
void selection_sort(int a[], int NUMELEMS);
void swap(int* arr, int a, int b);
void printArray(int a[], int NUMELEMS);

int main()
{
  int n = 0;
  int k = 0;
  double averageHeap = 0;
  double averageSelect = 0;
  cout << "Please enter an integer: ";
  cin >> n;
  int *a = new int[n];
  srand(time(NULL));
  //int a[] = {9, 2, 8, 7, 3};
  // Test heap sort performance
  for(int i = 0; i < REPS; i++)
  {
  for(int j = 0; j < n; j++)
    a[j] = rand()%20001 + (-10000); // randomize array [-7000,7000]
  auto start = std::chrono::steady_clock::now();
  heap_sort(a, n);
  auto end = std::chrono::steady_clock::now();
  averageHeap += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  }
  averageHeap /= REPS;

  // Test selection sort performance
  auto start = std::chrono::steady_clock::now();
  selection_sort(a, n);
  auto end = std::chrono::steady_clock::now();
  averageSelect += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  printArray(a, n);
  printf("Heap Sort took: %.2f ns on average\n", averageHeap);
  printf("Selection Sort took: %.2f ns on average\n", averageSelect);
  return 0;
}

void build_MaxHeap(int a[], int NUMELEMS)
{
  for(int i = ((NUMELEMS/2) - 1); i >= 0; i--)
    max_heapify(a, NUMELEMS, i); // passes the last index
}

void heap_sort(int a[], int NUMELEMS)
{
  build_MaxHeap(a, NUMELEMS);
  for(int i = NUMELEMS - 1; i >= 1; i--)
  {
    swap(a, 0, i); // swap root with last
    max_heapify(a, i - 1, 0); // change bounds of array and pass first elem
  }
}

void max_heapify(int a[], int NUMELEMS, int index)
{
  int maxIndex = index;
  int leftIndex = (2 * index) + 1;
  int rightIndex = (2 * index) + 2;
  if((leftIndex <= NUMELEMS) && (a[leftIndex] > a[maxIndex]))
    maxIndex = leftIndex;
  if((rightIndex <= NUMELEMS) && (a[rightIndex] > a[maxIndex]))
    maxIndex = rightIndex;
  if(maxIndex != index)
  {
    swap(a, maxIndex, index);
    max_heapify(a, NUMELEMS, maxIndex); // max value should be at the first
  }
}

void selection_sort(int a[], int NUMELEMS)
{
  int swaps = 0;
  do{
    for(int i = 0; i < NUMELEMS; i++)
    {
      if((a[i] > a[i + 1]) && ((i + 1) < NUMELEMS))
      {
        swap(a, i, i + 1);
        swaps++;
      }
    }
    if(swaps == 0)
      break;
    swaps = 0;
  }while(1);
}

void swap(int* arr, int a, int b)
{
    int temp = *(arr + a);
    *(arr + a) = *(arr + b);
    *(arr + b) = temp;
}

void printArray(int a[], int NUMELEMS)
{
  for(int i = 0; i < NUMELEMS; i++)
    printf("\t%d\n", a[i]);
}
