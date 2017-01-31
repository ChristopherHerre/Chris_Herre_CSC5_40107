
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 31, 2017, 1:27 PM
 * 
 * 7. Celsius Temperature Table
 * The formula for converting a temperature from Fahrenheit to Celsius is
 * 
 * C = 5/9 (F - 32)
 * 
 * where F is the Fahrenheit temperature and C is the Celsius temperature.
 * Write a function named celsius that accepts a Fahrenheit temperature as an
 * argument. The function should return the temperature, converted to Celsius.
 * Demonstrate the function by calling it in a loop that displays a table of
 * the Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
 * 
 */

#include <iostream>

using namespace std;

float celsius(float);

int main(int argc, char** argv) {
    for (int i = 0; i <= 20; i++)
    {
        cout << i << " Fahrenheit\t=\t" << celsius(i) << " Celsius" << endl;
    }
    return 0;
}

float celsius(float fahr)
{
    return 5/9.0 * (fahr - 32);
}