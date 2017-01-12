
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
    // Madison County has a senior citizen tax exemption
    short exemption = 5000;
    
    cout << "Enter the actual value of the property: ";
    // user input
    cin >> actualValue;
    
    cout << "Enter the property tax (Example: 2.64): ";
    cin >> propTax;
    
    cout << setprecision(2) << fixed;
    
    // 60 percent of actualValue
    assessValue = 0.6f * actualValue;
    
    assessValue -= exemption;
    
    cout << "Assessment Value: $" << assessValue << endl;
    
    // get the percent
    propTax /= 100;
    
    // output results
    cout << "Annual Property tax = $" << assessValue * propTax << endl;
    cout << "Quarterly Property tax = $" << (assessValue * propTax) / 4 << endl;
    return 0;
}
