#include <iostream>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <algorithm> // partition
using namespace std;

#define REPS 100
#define mid (low + high) / 2
int quick_select(int a[], int NUMELEMS, int low, int high, int k);
void KGreatestVals(int a, int NUMELEMS, int low, int high ,int k)
int partition(int a[], int NUMELEMS, int low, int high);
void printArray(int a[], int NUMELEMS);
void swap(int* arr, int a, int b);

int main()
{
  int n = 0;
  int k = 0;
  double average = 0;
  cout << "Please enter an integer: ";
  cin >> n;
  cout << "Please enter a Kth least integer less than the last integer: ";
  cin >> k;
  int *a = new int[n];
  srand(time(NULL));
  // Quick Sort
  //for(int i = 0; i < REPS; i++)
  //{
    for(int j = 0; j < n; j++)
      a[j] = rand()%14001 + (-7000); // randomize array [-7000,7000]
    auto start = std::chrono::steady_clock::now();
    cout << quick_select(a, n, 0, (n - 1), k) << endl;
    auto end = std::chrono::steady_clock::now();
    average += double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
  //}
  // average /= REPS;
  printArray(a, n);
  printf("Quick select took: %.2f ns on average\n", average);
  return 0;
}

int quick_select(int a[], int NUMELEMS, int low, int high, int k)
{
  if((k > 0) && (k <= (high - low + 1)))
  {
    int j = partition(a, NUMELEMS, low, high); // set pivot
    if(j - low == k - 1)
      return a[j];
    if (j - low > k - 1)
      return quick_select(a, NUMELEMS, low, j - 1, k); // partition left
    else
      return quick_select(a, NUMELEMS, j + 1, high, k - j + low - 1); // partition right
  }
}

int partition(int a[], int NUMELEMS, int low, int high)
{
  int pivot = a[high]; // set pivot to the far right index
  int i = (low - 1);
  for(int j = low; j < high; j++)
  {
    if(a[j] < pivot)
    {
        i++;
        swap(a, i, j);
    }
  }
  swap(a, i + 1, high);
  return i;
}

void KGreatestVals(int a, int NUMELEMS, int low, int high ,int k)
{
  if((k > 0) && (k <= (high - low + 1)))
  {
    int j = partition(a, NUMELEMS, low, high); // set pivot
    if(j - low == k - 1){
      for(int i = NUMELEMS - 1; i >= k; i--)
        cout << a[i] << endl;
      }
    if (j - low < k - 1)
      KGreatestVals(a, NUMELEMS, low, j - 1, k); // partition left
    else
      KGreatestVals(a, NUMELEMS, j + 1, high, k - j + low - 1); // partition right
  }
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
