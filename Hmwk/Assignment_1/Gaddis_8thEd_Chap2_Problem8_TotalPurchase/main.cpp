
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 7, 2017, 11:14 PM
 * 
 * 8. Total Purchase
 * A customer in a store is purchasing five items. The prices of the five items
 * are:

 * $15.95
 * $24.95
 * $6.95
 * $12.95
 * $3.95
 * 
 * Write a program that holds the prices of the five items in five variables.
 * Display each item’s price, the subtotal of the sale, the amount of sales tax,
 * and the total. Assume the sales tax is 7%.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    float item1Price = 15.95f;
    float item2Price = 24.95f;
    float item3Price = 6.95f;
    float item4Price = 12.95f;
    float item5Price = 3.95f;
    // the total of all five items before tax
    float sub = item1Price + item2Price + item3Price + item4Price + item5Price;
    // the percentage of sales tax
    float salesTax = .07f;
    // calculate the total after sales tax
    float total = (sub * salesTax) + sub;
    
    // output the results each on a new line
    cout << "Item1 price: $" << item1Price << "\n"
            "Item2 price: $" << item2Price << "\n"
            "Item3 price: $" << item3Price << "\n"
            "Item4 price: $" << item4Price << "\n"
            "Item5 price: $" << item5Price << "\n" 
            "Subtotal: $" << sub << "\n"
            "Sales tax: " << salesTax << "%\n"
            "Total: $" << total << "\n"
            << endl;
    return 0;
}

