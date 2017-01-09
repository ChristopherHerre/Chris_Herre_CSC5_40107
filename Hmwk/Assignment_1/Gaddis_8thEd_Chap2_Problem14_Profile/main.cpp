
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 5, 2017, 5:56 PM
 * 
 * 14. Personal Information
 * Write a program that displays the following pieces of information, each on
 * a separate line:
 * 
 * Your name,
 * Your address, with city, state, and ZIP code
 * Your telephone number
 * your college major.
 * Use only a single cout statement to display all of this information.
 * 
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // create a string array of labels
    string labels[] = { "Name:\t", "Address:", "City:\t", "State:\t", "Zip:\t",
                        "Phone #:", "Major:\t" };
    
    // create a string array of the info that corresponds to each label.
    string info[] = { "Jimbob", "123 abc st.", "Riverside", "CA", "92503",
                      "951-555-8888", "Sociology" };
    
    // Loop 7 times
    for (unsigned char i = 0; i < 7; i++)
    {
        // output the string values by their index i variable.
        cout << labels[i] << info[i] << endl;
    }
    // exit the program
    return 0;
}

