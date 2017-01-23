
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

int main(int argc, char** argv) {

    return 0;
}

int getNumAccidents(string region)
{
    short accidents;
    
    cout << "What is the number of automobile accidents in the " << region
            << " region? ";
    cin >> accidents;
    
    if (accidents < 0)
    {
        
    }
}

void findLowest()
{
    
}

