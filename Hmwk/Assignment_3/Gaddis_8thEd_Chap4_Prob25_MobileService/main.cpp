
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 12, 2017, 10:09 AM
 * 
 * 25. Mobile Service Provider
 * A mobile phone service provider has three different subscription packages
 * for its customers:
 * 
 * Package A: For $39.99 per month 450 minutes are provided. Additional minutes
 * are $0.45 per minute.
 * 
 * Package B: For $59.99 per month 900 minutes are provided. Additional minutes
 * are $0.40 per minute.
 * 
 * Package C: For $69.99 per month unlimited minutes provided.
 * 
 * Write a program that calculates a customer’s monthly bill. It should ask
 * which package the customer has purchased and how many minutes were used.
 * It should then display the total amount due.
 * 
 * Input Validation: Be sure the user only selects package A, B, or C.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    char package = 'A';
    short minutes = 0;
    float bill = 0;
    
    cout << "This program will calculate your phone bill.\n" << endl;
     
    // prompt user for their package input
    cout << "What package did you purchase (A, B, or C)? ";
    cin >> package;
    
    if (package != 'A' && package != 'B' && package != 'C')
    {
        cout << "The only valid inputs are A, B, or C. Goodbye!" << endl;
        return 0;
    }
    
    if (package != 'C')
    {
        // prompt user for minutes used
        cout << "How many minutes were used? ";
        cin >> minutes;
    }
    

    
    if (package == 'A')
    {
        // if minutes > 450, add 0.45 for each extra minute, to the 39.99 base
        // price
        bill = minutes > 450 ? 39.99 + ((minutes - 450) * 0.45) : 39.99;
    }
    else if (package == 'B')
    {
        // if minutes > 900, add 0.40 for each extra minute, to the 39.99 base
        // price
        bill = minutes > 900 ? 59.99 + ((minutes - 900) * 0.40) : 59.99;
    }
    else if (package == 'C')
    {
        // unlimited
        bill = 69.99;        
    }
    
    cout << "Bill: " << bill << endl;
    return 0;
}