
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 9, 2017, 5:11 PM
 * 
 * 14. Monthly Sales Tax
 * A retail company must file a monthly sales tax report listing the sales for
 * the month and the amount of sales tax collected. Write a program that asks
 * for the month, the year, and the total amount collected at the cash register
 * (that is, sales plus sales tax). Assume the state sales tax is 4 percent and
 * the county sales tax is 2 percent. If the total amount collected is known
 * and the total sales tax is 6 percent, the amount of product sales may be
 * calculated as:
 * 
 * S = T / 1.06
 * 
 * S is the product sales and T is the total income (product sales plus
 * sales tax).
 * 
 * The program should display a report similar to
 * 
 * 
 * Month: October
 * --------------------
 * Total Collected:     $ 26572.89
 * Sales:               $ 25068.76
 * County Sales Tax:    $ 501.38
 * State Sales Tax:     $ 1002.75
 * Total Sales Tax:     $ 1504.13
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    string month, year;
    float stateTax = 0.04f;
    float countyTax = 0.02f;
    float stateTaxAmt, countyTaxAmt, totalTaxAmt;
    
    // product sales
    float s,
            t;// total income
    
    cout << "Enter the month: ";
    cin >> month;
    
    cout << "Enter the year: ";
    cin >> year;
    
    cout << "Enter the total amount collected at the register: ";
    cin >> t;
    
    cout << 1 + stateTax + countyTax << endl;
    s = t / (1 + stateTax + countyTax);
    
    totalTaxAmt = t - s;
    countyTaxAmt = countyTax * s;
    stateTaxAmt = stateTax * s;
    
    system("clear");
    
    cout << setprecision(2) << fixed;
    cout << "Month: " << month <<  " Year: " << year
            << "\n-------------------------" << endl;
    cout << "Total Collected:\t$ " << t << endl;
    cout << "Sales:\t\t\t$ " << s << endl;
    cout << "County Sales Tax:\t$ " << countyTaxAmt << endl;
    cout << "State Sales Tax:\t$ " << stateTaxAmt << endl;
    cout << "Total Sales Tax:\t$ " << totalTaxAmt << endl;
    
    return 0;
}

