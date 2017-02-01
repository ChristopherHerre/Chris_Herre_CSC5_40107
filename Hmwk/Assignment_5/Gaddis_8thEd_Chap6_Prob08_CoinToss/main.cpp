
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 31, 2017, 3:08 PM
 * 
 * 8. Coin Toss
 * Write a function named coinToss that simulates the tossing of a coin. When
 * you call the function, it should generate a random number in the range of 1
 * through 2. If the random number is 1, the function should display “heads.”
 * If the random number is 2, the function should display “tails.” Demonstrate
 * the function in a program that asks the user how many times the coin should
 * be tossed and then simulates the tossing of the coin that number of times. 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void coinToss();

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    
    short flips;
    
    cout << "How many coin tosses? ";
    cin >> flips;
    
    cout << flips << endl;
    
    for (short i = 0; i < flips; i++)
    {
        cout << i + 1 << "\t";
        coinToss();
    }
    return 0;
}

void coinToss()
{
    short toss = (rand() % 2) + 1;
    
    cout << (toss == 1 ? "Heads" : "Tales") << endl;    
}

