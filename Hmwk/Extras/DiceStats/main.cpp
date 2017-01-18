/* 
 * File:   main.cpp
 * Author: Chris Herre
 * Created on 1/18/2017 10:36 AM
 * Purpose:  Statistics for throwing 2 dice
 */

//System Libraries Here

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    unsigned int nGames = 100000000;
    unsigned int wins = 0, losses = 0;
    unsigned int avgThrow = 0;
    short maxThrow = 0;
    
    // loop and take dice statistics
    for (int game = 1; game <= nGames; game++)
    {
        // call random number generator for the dice
        char die1 = rand() % 6 + 1; // value from 1-6
        char die2 = rand() % 6 + 1;
        char sum = die1 + die2;
        unsigned int cntThrow = 1;
        avgThrow++;
        if (sum == 2 || sum == 3 || sum == 12)
        {
            losses++;
            
        }
        else if (sum == 7 || sum == 11)
        {
            wins++;
            
        }
        else
        {
            bool keepThrowing = true;
            do
            {
                die1 = rand() % 6 + 1; // value from 1-6
                die2 = rand() % 6 + 1;
                avgThrow++;
                cntThrow++;
                char sum2 = die1 + die2;
                
                if (sum2 == 7)
                {
                    losses++;
                    keepThrowing = false;
                }
                else if (sum2 == sum)
                {
                    wins++;
                    keepThrowing = false;
                }
            } while (keepThrowing);
        }
        if (maxThrow < cntThrow)
        {
            maxThrow = cntThrow;
        }
    }
    
    //Output Located Here
    cout << "Total games played:\t" << nGames << endl;
    cout << "wins:\t" << wins << endl;
    cout << "losses:\t" << losses << endl;
    cout << "Percentage wins:\t" << 100.0f * wins / nGames << "%" << endl;
    cout << "Percentage losses:\t" << 100.0f * losses / nGames << "%" << endl;
    cout << "Average number of throws per game:\t" << static_cast<float>(avgThrow) / nGames << endl;
    cout << "Max throw:\t" << maxThrow << endl;
    return 0;
}

