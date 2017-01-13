
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 12, 2017, 10:09 AM
 * 
 * 26. Mobile Service Provider, Part 2
 * Modify the Program in Programming Challenge 25 so that it also displays how
 * much money Package A customers would save if they purchased packages B or C,
 * and how much money Package B customers would save if they purchased
 * Package C. If there would be no savings, no message should be printed.
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
    
    // if package C, minutes don't matter, don't ask
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
    
    cout << "Bill: $" << bill << endl;
    
    if (package == 'A')
    {
        // what the bill would be if plan B was chosen
        float planB = minutes > 900 ? 59.99 + ((minutes - 900) * 0.40) : 59.99;
        // the savings from the current bill minus what the plan B bill would be
        float savingsB = bill - planB;
        // the savings from the current bill minus the plan C bill
        float savingsC = bill - 69.99;
        
        // if no savings, don't display this message
        if (savingsB > 0)
        {
            cout << "Had you have chosen package B, you would have saved: $"
                    << savingsB << endl;
        }
        
        // if no savings, don't display this message
        if (savingsC > 0)
        {
            cout << "Had you have chosen package C, you would have saved: $"
                    << savingsC << endl;
        }
    }
    else if (package == 'B')
    {
        // the savings of choosing pack C over B
        float savings = bill - 69.99;
        
        // if no savings, don't display this message
        if (savings > 0)
        {
            cout << "Had you have chosen package C, you would have saved: $"
                    << savings << endl;
        }
    }
    return 0;
}