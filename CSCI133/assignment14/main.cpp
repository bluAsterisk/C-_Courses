#include <iostream>
#include "LinearHashing.h"
using namespace std;


template <class T, class E>
struct city
{
  T value;
  E name;
};

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
  void insert(HashTable *hashArray, int keyVal, string str);
  City<T, E> *holder
};

int hash(HashTable *hashArray, int keyVal)
{
  // h(k) = k mod 19
  int index;
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


int main()
{
HashTable hash[19];
// 18 Laguna Niguel
// 41 Mission Viejo
// 22 Lake Forest
// 44 Irvine
// Delete key 18
// 59 San Clemente
// 32 San Diego
// 49 Anaheim
// Delete key 22
// 73 Los Angeles
// 17 Orange
// 77 Palms Springs
// 26 Riverside
// Delete key 49
// 19 Brea
// 60 Santa Ana
// 35 Tustin
// 52 Oceanside
// 11 La Jolla
// 18 Del Mar
// 22 Aliso Viejo
// 49 Laguna Beach
}
