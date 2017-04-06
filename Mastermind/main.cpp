/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on April 5, 2017, 10:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void initSolution(short* solution, short pegs, short pegTypes);
void displaySolution(short* solution, short pegs, bool end);
short checkContains(short* solution, short pegs, short val,
        vector<short> guessedVals);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    bool end = false;
    // the solution set will consist of 4 pegs
    const short SOLUTION_PEGS = 4;
    // we have 6 different possible peg colors, or values
    const short PEG_TYPES = 6;
    // the solution set of 4 values
    short *solution = new short[SOLUTION_PEGS];
    vector<short> guessedVals;
    cout << "vector size: " << guessedVals.size() << endl;
    char guess;
    
    initSolution(solution, SOLUTION_PEGS, PEG_TYPES);
    
    while (true)
    {
        cout << "end= " << (end ? "true" : "false") << endl;
        displaySolution(solution, SOLUTION_PEGS, end);
        
        cin >> guess;
        cout << "guess=" << guess << endl;
        
        // a command to reveal the solution early
        if (guess == '!')
        {
            //cout << "END = TRUE" << endl;
            end = true;
        }
        short checkedGuess = checkContains(solution, SOLUTION_PEGS, guess - 48,
                guessedVals);
        guessedVals.push_back(checkedGuess);
        cout << "checkContains="
                << checkedGuess << endl;
    }
    
    delete[] solution;
    return 0;
}

// randomly generates a 4 value solution
void initSolution(short* solution, short pegs, short pegTypes)
{
    for (short i = 0; i < pegs; i++)
    {
        solution[i] = static_cast<short>(rand() % pegTypes);
    }
}

// prints the 4 value solution
void displaySolution(short* solution, short pegs, bool end)
{
    cout << "\t\t";
    for (short i = 0; i < pegs; i++)
    {
        cout << (end ? static_cast<char>(solution[i] + 48) : '*') << "  ";
    }
    cout << endl;
}

// returns the index of a given value, if contained within the solution set
short checkContains(short* solution, short pegs, short val,
        vector<short> guessedVals)
{
    for (short i = 0; i < pegs; i++)
    {
        if (find(guessedVals.begin(), guessedVals.end(), val) == guessedVals.end()
                && solution[i] == val)
        {
            return i;
        }
    }
    return -1;
}