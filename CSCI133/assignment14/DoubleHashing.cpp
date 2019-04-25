
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <class T, class E>
  struct City
{
  T value;
  E name;
};

//code for double hashing
template <class T, class E>
class Hash
{

 public:

  Hash(){for (int i = 0; i < 19; i++)holder[i]=NULL;}
  ~Hash(){delete *holder;}
  void insert(T num , E city);
  void display();
  void remove(T num);
  void search(T num);
  int spot(T num);
  bool spotOpen(T indexSpot);


 private:

  void insert2(T num, City<T,E> *& newCity);
  City<T,E> *holder[19];
};

template <class T, class E>
  void Hash<T,E> :: insert(T num , E city)
{
  City<T,E> *newCity = new City<T,E>;

  newCity->value = num;
  newCity->name = city;

  insert2(num, newCity);

}

template <class T, class E>
  void Hash<T,E> :: insert2(T num,City<T,E> *&newCity)
{

  int x;
  x = spot(num);
  holder[x] = newCity;

}

template <class T, class E>
  int Hash<T,E> :: spot(T num)
{
  int index, index2, index3;
  bool spotD;
  int j = 0;
  index = num % 19;
  index2 = 17 - num % 17;
  spotD = spotOpen(index);

  if(spotD == false)
   {

     do
      {
	index3 = (index + (j*index2)) % 19;
  spotD = spotOpen(index3);
  j++;
      }while(spotD == false);
     return index3;
   }

  return index;
}

template <class T, class E>
bool Hash<T,E> :: spotOpen(T indexSpot)
{

  if ( holder[indexSpot] != NULL)
    {
   return false;
    }
  else if ( indexSpot > 19)
    {
    return false;
    }
  else
    return true;

}

template <class T, class E>
void Hash<T,E> :: display()
{

  for(int i = 0 ; i < 19; i++)
    {
      if( holder[i] != NULL)
	{
      cout << "Cities [" << i << "] = " << holder[i]->name << ", "  << holder[i]->value << endl;
      	}
      else
      {
        cout << "Cities [" << i << "] = " << endl;
      }
    }
}

template <class T, class E>
void Hash<T,E> :: remove(T num)
{

  for(int i = 0 ; i < 19; i++)
    {

      if( holder[i] != NULL && holder[i]->value == num)
        {
	  holder[i] = NULL;

	}

    }

}

template <class T, class E>
void Hash<T,E> :: search(T num)
{

for(int i = 0 ; i < 19; i++)
  {
    if( holder[i] != NULL && holder[i]->value == num)
      {
	cout << holder[i]->value << " " << holder[i]->name << endl;
	break;
      }
  }

}
//end code for double hashing



int main()
{

  Hash<int,string> table;

  table.insert(18,"Laguna Niguel");
  table.insert(41,"Mission Viejo");
  table.insert(22,"Lake Forest");
  table.insert(44,"Irvine");
  table.remove(18);
  table.insert(59,"San Clemente");
  table.insert(32,"San Diego");
  table.insert(49,"Anaheim");
  table.remove(22);
  table.insert(73,"Los Angeles");
  table.insert(17,"Orange");
  table.insert(77,"Palm Springs");
  table.insert(26,"Riverside");
  table.remove(49);
  table.insert(19,"Brea");
  table.insert(60,"Santa Ana");
  table.insert(35,"Tustin");
  table.insert(52,"Oceanside");
  table.insert(11,"La Jolla");
  table.insert(18,"Del Mar");
  table.insert(22,"Aliso Viejo");
  table.insert(49,"Laguna Beach");
  table.display();

  return 0;

}
