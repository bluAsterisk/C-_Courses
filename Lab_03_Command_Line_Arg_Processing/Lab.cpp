#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    int numbersArray[10];
    int args, sum, range, low, high;
    double average;
    sum = average = range = low = high = 0;
    args = argc - 1;// first arg is the executable
    if(args == 0)
    {
      cout << "no arguments entered, I'm done \n";
      return 0;
    }
    else if(args < 3){
      cout << "Please enter more than 3 numerical arguments\n";
      return 0;
    }
    else if(args > 10)
    {
      cout << "more than 10 arguments, too many\n";
      return 0;
    }
    else
    {
      // check range
      for(int i = 0; i < args; ++i)
      {
          if((atoi(argv[i + 1]) < -100) || (atoi(argv[i + 1]) > 100))
          {
            cout << "add arguments between -100 and +100\n";
            return 0;
          }
          numbersArray[i] = atoi(argv[i + 1]); // load array
      }
      printf("The numbers received are being buffered up as follows:\n");
      for(int i = 0; i < args; ++i)
      {
          if(i == 0)
            low = high = numbersArray[i]; // record the first entry
          printf("numbersArray[%d] = %d\n", i, numbersArray[i]); // display array
          sum += numbersArray[i]; // accumulate
          if(numbersArray[i] < low) // record low
            low = numbersArray[i];
          if(numbersArray[i] > high) // recond high
            high = numbersArray[i];
      }
      average = sum / args;
      range = high - low;
      printf("The sum is %d\n", sum);
      printf("The average is %.1f\n", average);
      printf("The range is %d\n", range);
      return 0;
    }
}
