
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 23, 2017, 12:40 PM
 * 
 * 5. Falling Distance
 * When an object is falling because of gravity, the following formula can be
 * used to determine the distance the object falls in a specific time period:
 * 
 * d = 1/2gt^2
 * 
 * The variables in the formula are as follows: d is the distance in meters, g
 * is 9.8, and t is the amount of time, in seconds, that the object has been
 * falling.
 * 
 * Write a function named fallingDistance that accepts an object’s falling time
 * (in seconds) as an argument. The function should return the distance, in
 * meters, that the object has fallen during that time interval. Write a
 * program that demonstrates the function by calling it in a loop that passes
 * the values 1 through 10 as arguments and displays the return value. 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

float fallingDistance(short time)
{
    return 0.5 * 9.8 * (time * time);
}

int main(int argc, char** argv) {
    for (int i = 1; i <= 10; i++)
    {
        cout << "Distance: " << fallingDistance(i) << endl;
    }
    return 0;
}

