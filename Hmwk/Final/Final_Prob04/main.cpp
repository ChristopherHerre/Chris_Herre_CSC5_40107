
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 13, 2017, 6:31 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // the sequence of numbers
    short numbers[] = { 9, 52, 78, 101, 119 };
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    // the frequency variables for each number in the sequence
    // initialize all to 0
    int freq[5] = {};
    
    for (int i = 0; i < 10000; i++)
    {
        // select a random choice from the sequence
        short choice = numbers[rand() % 5];
        // count up the occurances and store them
        switch (choice)
        {
            case 9:
                freq[0]++;
                break;
            case 52:
                freq[1]++;
                break;
            case 78:
                freq[2]++;
                break;
            case 101:
                freq[3]++;
                break;
            case 119:
                freq[4]++;
                break;
        }
    }
    
    // display the occurances
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
            case 0:
                cout << "9 occured ";
                break;
            case 1:
                cout << "52 occured ";
                break;
            case 2:
                cout << "78 occured ";
                break;
            case 3:
                cout << "101 occured ";
                break;
            case 4:
                cout << "119 occured ";
                break;
        }
        cout << freq[i];
        cout << " times." << endl;
        
    }
    
    return 0;
}

