
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 12, 2017, 10:09 AM
 * 
 * 27. Mobile Service Provider, Part 3
 * Months with 30 days have 720 hours, and months with 31 days have 744 hours.
 * February, with 28 days, has 672 hours. You can calculate the number of
 * minutes in a month by multiplying its number of hours by 60. Enhance the
 * input validation of the Mobile Service Provider program by asking the user
 * for the month (by name), and validating that the number of minutes entered
 * is not more than the maximum for the entire month. Here is a table of the
 * months, their days, and number of hours in each.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char package = 'A';
    int minutes = 0;
    float bill = 0;
    // the month string entered by the user
    string month;
    // the number of minutes in the month entered by the user
    int numMin;
    
    cout << "This program will calculate your phone bill.\n" << endl;
     
    // prompt user for their package input
    cout << "What package did you purchase (A, B, or C)? ";
    cin >> package;
    
    if (package != 'A' && package != 'B' && package != 'C')
    {
        cout << "The only valid inputs are A, B, or C. Goodbye!" << endl;
        return 0;
    }
    
    cout << "For what month would you like to see the phone bill? "
            "(Capitalize first letter) ";
    cin >> month;
    
    if (month == "January")
    {
        numMin = 744 * 60;
    }
    else if (month == "February")
    {
        numMin = 672 * 60;
    }
    else if (month == "March")
    {
        numMin = 744 * 60;;
    }        
    else if (month == "April")
    {
        numMin = 720 * 60;
    }       
    else if (month == "May")
    {
        numMin = 744 * 60;
    }    
    else if (month == "June")
    {
        numMin = 720 * 60;
    }    
    else if (month == "July")
    {
        numMin = 744 * 60;
    }    
    else if (month == "August")
    {
        numMin = 744 * 60;
    }    
    else if (month == "September")
    {
        numMin = 720 * 60;
    }    
    else if (month == "October")
    {
        numMin = 744 * 60;
    }    
    else if (month == "November")
    {
        numMin = 720 * 60;
    }    
    else if (month == "December")
    {
        numMin = 744 * 60;
    }    
    
    // if package C, minutes don't matter, don't ask
    if (package != 'C')
    {
        // prompt user for minutes used
        cout << "How many minutes were used? ";
        cin >> minutes;
    }
    
    // if minutes entered is greater than minutes in the chosen month
    if (minutes > numMin)
    {
        cout << "The number of minutes is greater than the total minutes "
                "in the month of " << month << "." << endl;
        return 0;
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
