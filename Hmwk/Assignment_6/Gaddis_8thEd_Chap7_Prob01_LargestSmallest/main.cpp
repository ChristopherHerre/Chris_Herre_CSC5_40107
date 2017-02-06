
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 6, 2017, 10:32 AM
 * 
 * 1. Largest/Smallest Array Values
 * Write a program that lets the user enter 10 values into an array. The
 * program should then display the largest and smallest values stored in the
 * array. 
 * 
 */

#include <cstdlib>
#include <iostream>

bool isValidChar(char);

using namespace std;

int main(int argc, char** argv) {
    // an array to store 10 characters
    char characters[10];
    
    cout << "Valid inputs are A-Z, a-z, or 1-9" << endl;
    
    // loop 10 times
    for (short i = 0; i < 10; i++)
    {
        // ask for 10 characters, store to the characters array
        cout << "Enter a value into the array index " << i << ": ";
        cin >> characters[i];
        
        // validate characters[i]
        if (!isValidChar(characters[i]))
        {
            // invalid character has been entered, ask for this indexes
            // character again
            cout << "Error: You entered an invalid character. Try again." << endl;
            cout << "Enter a value into the array index " << i << ": ";
            cin >> characters[i];
        }
    }
    
    char temp;
    bool swap;
    int index = 0;
    
    // bubble sort the array
    // array may potentially already be sorted
    do
    {
        //cout << index++ << endl;
        swap = false;
        for (short j = 0; j < 10 - 1; j++)
        {
            if (characters[j] > characters[j + 1])
            {
                temp = characters[j + 1];
                characters[j + 1] = characters[j];
                characters[j] = temp;
                swap = true;
            }
        }
    } while (swap);
    
    // output the lowest and highest values in the array
    for (short k = 0; k < 10; k++)
    {
        if (k == 0 || k == 9)
        {
            cout << (k == 0 ? "Lowest: " : "Highest: ");
        }
        cout << characters[k] << endl;
    }
    return 0;
}

// returns true if the parameter character is a valid input
bool isValidChar(char c)
{
    char valids[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    for (char v : valids)
    {
        if (c == v)
        {
            return true;
        }
    }
    return false;
}