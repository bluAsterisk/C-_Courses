class HashTable
{
public:
  HashTable()
  {
    key = NULL;
    city = NULL;
  }

  void insert(HashTable *hashArray, int keyVal, string str);
  void remove(HashTable *hashArray, int keyVal);
  void DispHashTable(HashTable *hashArray);
private:
  int key;
  string city;
  int hash(HashTable *hashArray, int keyVal);
};

int hash(HashTable *hashArray, int keyVal)
{
  // h(k) = k mod 19
  int index = 0;
  index = keyVal % 19;
  return index;
}

void HashTable::insert(HashTable *hashArray, int keyVal, string str)
{
  int index = hash(hashArray, keyVal); // hash for index
  int looped = 0; // check if entire list has been traversed
  // if first index is available, no collision
  // else, tranverse array for available index
  for(int i = index; i < hashArray.length(); ++i)
  {
    // available
    if(hashArray[i] == NULL)
    {
      hashArray[i].key = keyVal;
      hashArray[i].city = str;
      break;
    }
    // if end of array, loop again
    else if(looped)
      break;
    else if(index == (hashArray.length() - 1))
    {
      index = 0;
      ++looped;
    }
  }
}

void HashTabele::remove(HashTable *hashArray, int keyVal)
{
  int index = hash(hashArray, keyVal);
  hashArray[index].key = NULL;
  hashArray[index].city = NULL;
}





#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

struct  hTable
{
    int     key;
    string  city;
};


int main()
{
    hTable  tArray[] = {{18, "Laguna Niguel"}, {41, "Mission Viejo"},
                          {22, "Lake Forest"}, {44, "Irvine"},
                          {59, "San Clemente"}, {32, "San Diego"},
                          {49, "Anaheim"}, {73, "Los Angeles"}, {17, "Orange"},
                          {77, "Palms Springs"}, {26, "Riverside"},
                          {19, "Brea"}, {60, "Santa Ana"}, {35, "Tustin"},
                          {52, "Oceanside"}, {11, "La Jolla"}, {18, "Del Mar"},
                          {22, "Aliso Viejo"}, {49, "Laguna Beach"}};

    hTable  lProb[19] = {0, ""};
    int     index;
    int     subIndex = 0;


//==============================================================================
//  Linear Probing
//==============================================================================

    cout << "Linear Probing";
    cout << endl;

    for (index = 0; index < 19; ++index)
        {
        // delete key 18
        if (index == 4)
            {
             lProb[18].key = 0;
             lProb[18].city = " ";
            }

        // delete key 22
        if (index == 8)
            {
             lProb[4].key = 0;
             lProb[4].city = " ";
            }

        // delete key 49
        if (index == 13)
            {
             lProb[11].key = 0;
             lProb[11].city = " ";
            }

        // find index to insert value into
        subIndex = tArray[index].key % 19;

        // if index is empty insert here
        if (lProb[subIndex].key == 0)
            {
            lProb[subIndex].key = tArray[index].key;
            lProb[subIndex].city = tArray[index].city;
            }

        // if index is occupied move onto next index
        else
            {
             ++subIndex;

             // keep searching array for empty key structure index
             while (lProb[subIndex].key != 0)
                {
                ++subIndex;

                // if you reach the end of the array move back to beginning
                if (subIndex > 18)
                    {
                    subIndex = 0;
                    }
                }

            // once open spot found insert values here
            lProb[subIndex].key = tArray[index].key;
            lProb[subIndex].city = tArray[index].city;

            } // end of "else"

        } // end of "for"

    subIndex = 0;
    // display contents of array
    for (index =0; index < 19; ++index)
        {
            cout <<"lProb["<< index << "] = " << lProb[index].key << " ";
            cout << lProb[index].city << endl;
        }

    cout << endl;
    cout << "Quadratic Probing";
    cout << endl;
