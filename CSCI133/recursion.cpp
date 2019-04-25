#include <iostream>
using namespace std;

int max(int array[], int n)
{
  if(n == 1)
    return array[0];
  if(array[n - 1] > max(array, n - 1))
    return array[n - 1];
  else
    return max(array, n - 1);
}

int min(int array[], int n)
{
  if(n == 1)
    return array[0];
  if(array[n - 1] < min(array, n - 1))
    return array[n - 1];
  else
    return min(array, n - 1);
}

int main()
{
  int array[] = {4, 6, 2, 7, 398, 332, 142, 66};
  int max;
  max = max(array, 9);
  int min;
  min = min(array, 9);
  cout << "Testing max recursive functions... \n";
  cout << "The max is " << max << endl;
  cout << "The min is " << min << endl;
  return 0;
}
