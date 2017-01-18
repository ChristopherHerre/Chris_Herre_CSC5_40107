
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 18, 2017, 1:38 PM
 * 
 * 5. Membership Fees Increase
 * A country club, which currently charges $2,500 per year for membership, has
 * announced it will increase its membership fee by 4% each year for the next
 * six years. Write a program that uses a loop to display the projected rates
 * for the next six years.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    float charge = 2500;
    
    // set format to two digits after the decimal
    cout << setprecision(2) << fixed;
    
    // loop 6 times
    for (int year = 0; year < 6; year++)
    {
        // print the current price and the raised price
        cout << "Year " << year + 1 << " - Current price $" << charge << " will go up to $";
        // calc the raised price
        charge += charge * 0.06;
        cout << charge << "." << endl;
    }
    return 0;
}

