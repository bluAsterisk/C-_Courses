#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <algorithm> // partition
using namespace std;

#define REPS 100
#define mid (low + high) / 2
void quick_sort(int a[], int NUMELEMS, int low, int high);
void insertion_sort(int a[], int NUMELEMS);
int partition(int a[], int NUMELEMS, int low, int high);
void printArray(int a[], int NUMELEMS);
void swap(int* arr, int a, int b);

int main()
{
  int n = 0;
  double average = 0;
  cout << "Please enter an integer: ";
  cin >> n;
  int *a = new int[n];
  srand(time(NULL));
  // Quick Sort
  //for(int i = 0; i < REPS; i++)
  //{
    for(int j = 0; j < n; j++)
      a[j] = rand()%14001 + (-7000); // randomize array [-7000,7000]
    auto start = std::chrono::steady_clock::now();
    quick_sort(a, n, 0, (n - 1));
    auto end = std::chrono::steady_clock::now();
    average += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  //}
  //average /= REPS;
  printArray(a, n);
  printf("Quick sort took: %.2f ns on average\n", average);

  // Inserition Sort
  //for(int i = 0; i < REPS; i++)
  //{
    for(int j = 0; j < n; j++)
      a[j] = rand()%14001 + (-7000); // randomize array [-7000,7000]
     start = std::chrono::steady_clock::now();
    insertion_sort(a, n);
     end = std::chrono::steady_clock::now();
    average += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  //}
  //average /= REPS;
  printArray(a, n);
  printf("Insertion sort took: %.2f ns on average\n", average);
  return 0;
}

void quick_sort(int a[], int NUMELEMS, int low, int high)
{
  if(low < high) // break when sorted (low == high)
  {
    int j = partition(a, NUMELEMS, low, high); // set pivot
    quick_sort(a, NUMELEMS, low, j); // sort left
    quick_sort(a, NUMELEMS, j+1, high); // sort right
  }
}

void insertion_sort(int a[], int NUMELEMS)
{
  for(int i = 1; i < NUMELEMS; i++) // start at 1 to check the second index (j-1) = -1
  {
    int key = a[i]; // index to compare
    int j = i - 1; // start from the previous index
    for(; j > 0; j--) // until index 1
    {
      if(a[j] > key)
        a[j + 1] = a[j]; // shift to the left
    }
    a[j] = key; // insert least to the front at index 0
  }
}

int partition(int a[], int NUMELEMS, int low, int high)
{
  int pivot = min(max(a[low], a[mid]), a[high]); // median of 3
  int i = low;
  int j = high;
  while(i <= j)
  {
    while(a[i] < pivot) // check from left
        i++;
    while(a[j] >= pivot) // check from right
        j--;
    swap(a, i, j);
    if(i > j) // once i and j cross, both sides have been arranged
      break;
  }
  swap(a, i + 1, pivot);
  return j;
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
