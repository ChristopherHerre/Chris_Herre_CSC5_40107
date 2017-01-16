
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 14, 2017, 9:07 PM
 * 
 * 1. Minimum/Maximum
 * Write a program that asks the user to enter two numbers. The program should
 * use the conditional operator to determine which number is the smaller and
 * which is the larger.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // declare variables for input storage
    float a, b;
    
    // prompt for input
    cout << "Enter two numbers and the program will determine which is smaller."
            << endl;
    cout << "First number: ";
    cin >> a;
    
    cout << "Second number: ";
    cin >> b;
    
    // check if inputs are equal
    if (a == b)
    {
        cout << "Inputs are equal." << endl;
        return 0;
    }
    
    // check if a is less than b
    if (a < b)
    {
        cout << a << " is less than " << b << "." << endl;
    } else {
        cout << b << " is less than " << a << "." << endl;
    }
    return 0;
}

