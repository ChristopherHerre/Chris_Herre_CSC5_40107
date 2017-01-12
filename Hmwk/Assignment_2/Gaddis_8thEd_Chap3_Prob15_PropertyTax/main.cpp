
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 10, 2017, 7:36 PM
 * 
 * 15. Property Tax
 * A county collects property taxes on the assessment value of property, which
 * is 60 percent of the property’s actual value. If an acre of land is valued
 * at $10,000, its assessment value is $6,000. The property tax is then 75¢ for
 * each $100 of the assessment value. The tax for the acre assessed at $6,000
 * will be $45. Write a program that asks for the actual value of a piece of
 * property and displays the assessment value and property tax.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    // create variable to store actual value input from user.
    // create assessValue variable to find the assessment value
    // of the properties actual value.
    float actualValue, assessValue, propTax;
    
    cout << "Enter the actual value of the property." << endl;
    // user input
    cin >> actualValue;
    
    // 60 percent of actualValue
    assessValue = 0.6f * actualValue;
    // 75 cents of every $100 of assessValue
    propTax = 0.75f;
    
    // get the percent
    propTax /= 100;
    
    // output results
    cout << setprecision(2) << fixed;
    cout << "Assessment Value = $" << assessValue << endl;
    cout << "Property tax = $" << assessValue * propTax << endl;
    
    return 0;
}