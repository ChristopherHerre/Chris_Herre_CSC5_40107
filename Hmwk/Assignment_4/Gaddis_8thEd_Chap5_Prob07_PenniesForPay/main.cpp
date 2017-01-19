
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 19, 2017, 12:14 AM
 * 
 * 7. Pennies for Pay
 * Write a program that calculates how much a person would earn over a period
 * of time if his or her salary is one penny the first day and two pennies the
 * second day, and continues to double each day. The program should ask the
 * user for the number of days.
 * 
 * Display a table showing how much the salary was for each day, and then show
 * the total pay at the end of the period. The output should be displayed in a
 * dollar amount, not the number of pennies.
 * 
 * Input Validation: Do not accept a number less than 1 for the number of days
 * worked.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    short days;
    // the user might want to know their pay after a year, so we need a double
    double pay = 0.01, sum = 0;
    
    // set format to two digits after decimal
    cout << setprecision(2) << fixed;
    
    // explain to user what program does
    cout << "This program will calculate a person's salary over time at 0.01"
            " per day, doubling daily.\n" << endl;
    // prompt for days worked        
    cout << "How many days has the person worked? ";
    cin >> days;
    
    // loop for every day
    for (int i = 1; i <= days; i++)
    {
        cout << "Day " << i << ": " << pay << endl;
        // add pay to sum
        sum += pay;
        // double pay
        pay *= 2;
    }
    
    // finally, print the total
    cout << "Salary: " << sum << endl;
    return 0;
}

