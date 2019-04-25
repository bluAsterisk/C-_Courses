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
//  Quadratic Probing
//==============================================================================

    cout << "Linear Probing";
    cout << endl;

    for (index = 0; index < 19; index = ((index + 1) * (index + 1)))
        {
          if(index >= 16)
            index = 19 - index;
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
    return 0;
}





int next_quadFormula(int searchKey, int level, int size)
{
	return (h(searchKey,size) + (level * level - level) / 2) % size;
}
void add_QuadraticProbing(int searchKey, string item, HashItem array[], int size)
{
        int position = h(searchKey,size);
        int level = 1;

        if(isAvailable(position, array))
        {
                HashItem newEntry = HashItem(searchKey, item);
                array[position] = newEntry;
        }
        else
        {
                int countItems = 1;

                if(position != (size-1))
                {
                        for(level; position < size; level++)
                        {
                        	position = next_quadFormula(searchKey,level,size);
                            if(isAvailable(position,array))
                            {
                            	HashItem newEntry = HashItem(searchKey,item);
                                array[position] = newEntry;
                                position = size;
                            }
                            countItems++;
                        }
                        if(position == size)
                        {
                                for(level; position < size; level++)
                                {
                                	position = next_quadFormula(searchKey,level,size);
                                	if(isAvailable(position,array))
									{
										HashItem newEntry = HashItem(searchKey,item);
										array[position] = newEntry;
										position = size;
									}
									else if(countItems == size)
									{
										cout << "Error: The array is full." << endl;
									}
									countItems++;
                                }
                        }
                }
                else if(position == size-1)
                {
                        for(level; position < size; level++)
                        {
                                if(isAvailable(i,array))
                                {
                                        HashItem newEntry = HashItem(searchKey,item);
                                        array[i] = newEntry;
                                        i = size;
                                }
                                else if(countItems == size)
                                {
                                        cout << "Error: The array is full." << endl;
                                }
                                countItems++;
                        }
                }
        }
}
