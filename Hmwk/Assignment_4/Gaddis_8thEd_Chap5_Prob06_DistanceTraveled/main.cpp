
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 18, 2017, 11:42 PM
 *
 * 6. Distance Traveled
 * The distance a vehicle travels can be calculated as follows:
 * distance = speed * time
 * For example, if a train travels 40 miles per hour for 3 hours, the distance
 * traveled is 120 miles.
 * 
 * Write a program that asks the user for the speed of a vehicle (in miles
 * per hour) and how many hours it has traveled. The program should then use a
 * loop to display the distance the vehicle has traveled for each hour of that
 * time period. Here is an example of the output:
 * 
 * What is the speed of the vehicle in mph? 40--------------------------------
 * How many hours has it traveled? 3
 * Hour     Distance Traveled
 * --------------------------------
 * 1        40
 * 2        80
 * 3        120
 * 
 * Input Validation: Do not accept a negative number for speed and do not accept
 * any value less than 1 for time traveled.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    float speed, hours;
    
    // prompt user to input speed
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    
    // check if speed is negative
    if (speed < 0)
    {
        cout << "Speed cannot be negative!" << endl;
        return 0;
    }
    
    // prompt user to input hours
    cout << "How many hours has it traveled? ";
    cin >> hours;
    
    // hours cannot be less than 1
    if (hours < 1)
    {
        cout << "Time traveled cannot be less than 1!" << endl;
        return 0;
    }
    
    // display table
    cout << "Hour\tDistance Traveled\n--------------------------------" << endl;
    
    // display distance traveled for each hour
    for (int i = 1; i <= hours; i++)
    {
        cout << i << "\t" << speed * i << endl;
    }
    return 0;
}

