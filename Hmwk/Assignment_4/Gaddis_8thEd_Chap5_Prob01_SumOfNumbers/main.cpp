
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 18, 2017, 12:12 PM
 * 
 * 1. Sum of Numbers
 * Write a program that asks the user for a positive integer value. The program
 * should use a loop to get the sum of all the integers from 1 up to the number
 * entered. For example, if the user enters 50, the loop will find the sum of
 * 1, 2, 3, 4, … 50.
 * 
 * Input Validation: Do not accept a negative starting number.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    float input, sum;
    // prompt user to input a number
    cout << "Enter a positive integer value: ";
    cin >> input;
    
    // if number is negative
    if (input < 0)
    {
        cout << "Input cannot be negative!" << endl;
        // exit program
        return 0;
    }
    
    // go through all numbers between 1 and the input number
    for (int i = 1; i <= input; i++)
    {
        // add i to sum
        sum += i; 
        cout << "Adding " << i << " to sum." << endl;
    }
    
    // print sum
    cout << "Sum =\t" << sum << endl;
    return 0;
}

