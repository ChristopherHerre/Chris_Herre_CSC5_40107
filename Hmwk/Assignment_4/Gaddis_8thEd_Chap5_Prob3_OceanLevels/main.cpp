
/* 
 * File: main.cpp
 * Author: Chris Herre
 *
 * Created on January 18, 2017, 12:29 PM
 * 
 * 3. Ocean Levels
 * Assuming the ocean’s level is currently rising at about 1.5 millimeters per
 * year, write a program that displays a table showing the number of
 * millimeters that the ocean will have risen each year for the next 25 years. 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    // left justify year
    // display labels
    cout << left << setw(8) << "Year"  << "Amount risen (in mm)" << endl;
    
    // loop 25 times
    for (int yearOffset = 0; yearOffset <= 25; yearOffset++)
    {
        // format our numbers to 2 digits after the decimal
        cout << setprecision(2) << fixed;
        
        // calc the amount risen per year
        float risen = yearOffset * 1.5;
        // display + or a blank space depending on if risen is positive
        cout << setw(8) << 2017 + yearOffset << (risen <= 0 ? " " : "+") << risen << endl;
    }
    return 0;
}

