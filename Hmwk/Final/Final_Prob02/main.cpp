
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 13, 2017, 4:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    // prompt the user for x
    short x;
    cout << "Enter the value of x: ";
    cin >> x;
    
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // 10^x
    unsigned int number = pow(10, x);
    // the number of guesses remaining
    short attempts = (log2(number) + 1);
    // randomly choose a number between 1 and number
    unsigned int ran = rand() % static_cast<unsigned int>(number);

    // prompt the user to guess
    cout << "I have a number between 1 and " << number << endl;
    cout << "Can you guess my number?  You will be\ngiven a maximum integer of "
            << attempts << " guesses.\nPlease type your first guess." << endl;
    
    int guess;
    
    // while the random number has not been guessed and attempts are remaining
    while (guess != ran && attempts > 0)
    {
        cin >> guess;
        attempts--;
        
        if (guess > ran)
        {
            cout << "Too High. Try again." << endl;
        }
        else if (guess < ran)
        {
            cout << "Too low. Try again." << endl;
        }
        else if (guess == ran)
        {
            cout << "Congratulations, You guessed the number! Would you like to "
                "play again(y or n)?" << endl;
        }
        cout << "Attempts: " << attempts << endl;
        
        if (attempts <= 0)
        {
            cout << "Too many tries." << endl;
            cout << "The answer was " << ran << endl;
        }
    }

    return 0;
}

