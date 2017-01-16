
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 14, 2017, 9:23 PM
 * 
 * 2. Roman Numeral Converter
 * Write a program that asks the user to enter a number within the range of 1
 * through 10. Use a switch statement to display the Roman numeral version of
 * that number.
 * 
 * Input Validation: Do not accept a number less than 1 or greater than 10.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    short input;
    string output;
    
    // prompt user for input
    cout << "Enter a number between 1 and 10: ";
    cin >> input;
    
    // handle all the possible values for input
    switch (input)
    {
        case 1:
            output = "I";
            break;
        case 2:
            output = "II";
            break;
        case 3:
            output = "III";
            break;
        case 4:
            output = "IV";
            break;
        case 5:
            output = "V";
            break;
        case 6:
            output = "VI";
            break;
        case 7:
            output = "VII";
            break;
        case 8:
            output = "VIII";
            break;
        case 9:
            output = "IX";
            break;
        case 10:
            output = "X";
            break;
        default :
            cout << "Only values 1-10 are accepted" << endl;
            return 0;
    }
    
    // output the resulting Roman numeral for the given input
    cout << output << ". This is the Roman numeral of " << input << "." << endl;
    return 0;
}

