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

using namespace std;

void initGuesses(short*, short);
void initSolution(short*, short, short);
void displaySolution(short*, short, bool);
void doFeedback(short*, short*, short&, short&, short);
void cleanUp(short*, short*, short*);
void doAttempt(short*, short*, short*, short, short, short);
void doPreattempt(short*, short*, short*, bool&, short, string);
void start(short*, short*, short*, string, string, bool&, short, short, short);

/*
 * Known bugs
 * 
 */

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    const short ATTEMPTS = 3;//8;
    // the solution set will consist of 4 pegs
    const short SOLUTION_PEGS = 4;
    // we have 6 different possible peg colors, or values
    const short PEG_TYPES = 6;
    const string WIN = "You Win!!!";
    const string LOST = "You Lost!";
    // the solution set of 4 values
    short *solution = new short[SOLUTION_PEGS];
    // the current guess set of 4 values
    // guessing the solution set
    short *guesses = new short[SOLUTION_PEGS];
    short *score = new short[SOLUTION_PEGS];
    bool gameOver = false;
    initSolution(solution, SOLUTION_PEGS, PEG_TYPES);
    // set the guesses display to all *s
    initGuesses(guesses, SOLUTION_PEGS);
    start(solution, guesses, score, WIN, LOST, gameOver, ATTEMPTS,
            PEG_TYPES, SOLUTION_PEGS);
    return 0;
}

void start(short* solution, short* guesses, short* score, string win,
        string lost, bool& gameOver, short attempts, short types, short pegs)
{
    cout << "A random solution set has been chosen. You will\nhave "
            << attempts << " attempts to guess all of the elements\n"
            "of the solution set to win the game. This version\nuses numbers "
            "0-" << types - 1 << " instead of colored pegs.\n" << endl;
    // display the answer to save Dr. Lehr time
    cout << "Debug ";
    displaySolution(solution, pegs, true);
    // attempts
    for (short i = 0; !gameOver && i < attempts; i++)
    {
        doPreattempt(solution, guesses, score, gameOver, pegs, win);
        cout << "ATTEMPT #" << i + 1 << endl;
        // current guesses
        for (short j = 0; j < pegs; j++)
        {
            doAttempt(solution, guesses, score, j, pegs, types);
        }
    }
    gameOver = true;
    displaySolution(solution, pegs, gameOver);
    if (guesses[0] == solution[0] && guesses[1] == solution[1]
            && guesses[2] == solution[2] && guesses[3] == solution[3])
    {
        cout << win << endl;
    }
    else
    {
        cout << lost << endl;
    }
    cleanUp(solution, guesses, score);
}

void cleanUp(short* solution, short* guesses, short* score)
{
    delete[] solution;
    delete[] guesses;
    delete[] score;
}

void initGuesses(short* guesses, short pegs)
{
    for (short k = 0; k < pegs; k++)
    {
        guesses[k] = -1;
    }
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
    cout << "Solution:\n";
    for (short i = 0; i < pegs; i++)
    {
        cout << (end ? static_cast<char>(solution[i] + 48) : '*') << "  ";
    }
    cout << endl;
}

// these are the black and white dots, for now just counter variables
void doFeedback(short* solution, short* guesses, short& black, short& white,
        short pegs)
{
     for (short l = 0; l < pegs; l++)
    {
        // correct number and is in the correct position
        if ((l == 0 && guesses[l] == solution[0])
                || (l == 1 && guesses[l] == solution[1])
                || (l == 2 && guesses[l] == solution[2])
                || (l == 3 && guesses[l] == solution[3]))
        {
            black++;
        }
        // correct number, but wrong position
        else if (solution[l] == guesses[0] || solution[l] == guesses[1]
                || solution[l] == guesses[2] || solution[l] == guesses[3])
        {
            white++;
        }
    }
    cout << "black:\t" << black << endl;
    cout << "white:\t" << white << endl;
}

// process the logic of a single attempt
void doAttempt(short* solution, short* guesses, short* score, short j,
        short pegs, short types)
{
    cout << "Enter a number 0-" << types - 1 << " for index " << j
            << " of the guess set: ";
    cin >> guesses[j];
    if (guesses[j] > types - 1 || guesses[j] < 0)
    {
        cout << "Critical error! Input cannot be greater than "
                << types - 1 << ", or less than 0!" << endl;
        cleanUp(solution, guesses, score);
        exit(0);
    }
    for (short k = 0; k < pegs; k++)
    {
        cout << (guesses[k] < 0
                ? '*' : static_cast<char>(guesses[k] + 48)) << " ";
    }
    cout << endl;
}

void doPreattempt(short* solution, short* guesses, short* score,
        bool& gameOver, short pegs, string win)
{
    // if the guesses set and the solution set
    // have equal elements, game over
    if (guesses[0] == solution[0] && guesses[1] == solution[1]
            && guesses[2] == solution[2] && guesses[3] == solution[3])
    {
        gameOver = true;
    }
    displaySolution(solution, pegs, gameOver);
    // handle game over and exit
    if (gameOver)
    {
        cleanUp(solution, guesses, score);
        cout << win << endl;
        exit(0);
    }
    short black = 0;
    short white = 0;
    doFeedback(solution, guesses, black, white, pegs);
    // reset the guesses display to all *s
    initGuesses(guesses, pegs);
}