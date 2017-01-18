
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 18, 2017, 1:25 PM
 * 
 * 4. Calories Burned
 * Running on a particular treadmill you burn 3.6 calories per minute. Write a
 * program that uses a loop to display the number of calories burned after
 * 5, 10, 15, 20, 25, and 30 minutes. 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    cout << "You are running on a treadmill . . ." << endl;

    // start at 5, loop till i = 30
    for (int i = 5; i <= 30; i+=5)
    {
        // do the conversion and output results
        cout << "Its been " << i << " minutes. You have burned " << i * 3.6 << " calories so far." << endl;
    }
    return 0;
}

