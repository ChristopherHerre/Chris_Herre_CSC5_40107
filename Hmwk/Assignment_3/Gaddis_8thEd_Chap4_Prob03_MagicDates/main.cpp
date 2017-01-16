
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 15, 2017, 11:58 AM
 * 
 * 3. Magic Dates
 * The date June 10, 1960 is special because when we write it in the following
 * format, the month times the day equals the year.
 * 
 * 6/10/60
 * 
 * Write a program that asks the user to enter a month (in numeric form), a day,
 * and a two-digit year. The program should then determine whether the month
 * times the day is equal to the year. If so, it should display a message saying
 * the date is magic. Otherwise it should display a message saying the date is
 * not magic.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    short month, day, year;
    
    // prompt user to enter a month
    cout << "Enter a month in numeric form: ";
    cin >> month;
    
    // prompt user for the day
    cout << "Enter a day: ";
    cin >> day;
    
    // prompt for two digit year
    cout << "Enter a two digit year: ";
    cin >> year;
    
    // check if the date is magic or not
    if (month * day == year)
    {
        cout << "The date is magic!" << endl;
    }
    else
    {
        cout << "The date is not magic." << endl;
    }
    return 0;
}

