
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 23, 2017, 11:44 AM
 * 
 * 4. Safest Driving Area
 * Write a program that determines which of five geographic regions within a
 * major city (north, south, east, west, and central) had the fewest reported
 * automobile accidents last year. It should have the following two functions,
 * which are called by main.
 * 
 * - int getNumAccidents() is passed the name of a region. It asks the user for
 * the number of automobile accidents reported in that region during the last
 * year, validates the input, then returns it. It should be called once for
 * each city region.
 * 
 * - void findLowest() is passed the five accident totals. It determines which
 * is the smallest and prints the name of the region, along with its accident
 * figure.
 * 
 * Input Validation: Do not accept an accident number that is less than 0.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int getNumAccidents(string);
void findLowest(short []);

const string REGIONS[] = { "north", "south", "east", "west", "central" };

int main(int argc, char** argv) {
    short numAccidents[5];

    // populate numAccidents array with the return value of getNumAccidents
    // for each region
    for (int i = 0; i < 5; i++)
    {
        numAccidents[i] = getNumAccidents(REGIONS[i]);
    }
    // call findLowest function
    findLowest(numAccidents);
    return 0;
}

int getNumAccidents(string region)
{
    short accidents;
    
    // prompt user to input the number of accidents for the given region
    cout << "What is the number of automobile accidents in the " << region
            << " region? ";
    cin >> accidents;
    
    // validate input, cannot be negative # of accidents
    if (accidents < 0)
    {
        cout << "Cannot accept an accident number less than 0!" << endl;
        return -1;
    }
    return accidents;
}

void findLowest(short accidents[])
{
    // set lowest to a value larger than any inputs to the accidents array
    short lowest = 30000;
    unsigned char lowestIndex = 0;
    
    // loop for each index in our regions array
    for (int i = 0; i < 5; i++)
    {
        if (accidents[i] < lowest)
        {
            lowestIndex = i;
            // reassign lowest to the actual lowest value so far
            // through the loop
            lowest = accidents[i];
        }
    }
    // output which region had the least accidents
    cout << "The " << REGIONS[lowestIndex] << " region had the least amount of"
            " accidents at " << lowest << " accidents last year." << endl;
}
