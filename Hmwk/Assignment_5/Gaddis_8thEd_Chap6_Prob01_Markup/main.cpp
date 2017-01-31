
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 23, 2017, 10:03 AM
 * 
 * 1. Markup
 * Write a program that asks the user to enter an item’s wholesale cost and its
 * markup percentage. It should then display the item’s retail price. For
 * example:
 * 
 * - If an item’s wholesale cost is 5.00 and its markup percentage is 100%, 
 * then the item’s retail price is 10.00.
 * 
 * - If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then
 * the item’s retail price is 7.50.
 * The program should have a function named calculateRetail that receives the
 * wholesale cost and the markup percentage as arguments and returns the retail
 * price of the item.
 * 
 * Input Validation: Do not accept negative values for either the wholesale
 * cost of the item or the markup percentage.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

float calculateRetail(float, float);

int main(int argc, char** argv) {
    float cost, markup;
    cout << fixed << setprecision(2);
    cout << "Enter an item's wholesale cost: ";
    cin >> cost;
    
    // check if cost is negative
    if (cost < 0)
    {
        cout << "Wholesale cost cannot be negative!" << endl;
        // exit early
        return 0;
    }
    
    cout << "Enter the markup percentage (Ex: 50% = 0.5): ";
    cin >> markup;
    
    // check if markup is negative
    if (markup < 0)
    {
        cout << "Markup percentage cannot be negative!" << endl;
        // exit early
        return 0;
    }
    
    cout << "Retail price = $" << calculateRetail(cost, markup) << endl;
    return 0;
}

// returns the retail price given cost and markup
float calculateRetail(float cost, float markup)
{
    return cost + (cost * markup);
}

