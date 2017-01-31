
/* 
 * File:   main.cpp
 * Author: Chris Herre
 * Purpose: Project One
 *
 * Created on January 29, 2017, 8:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string getEmpty(string);
void setGallows(string &, int);

int main(int argc, char** argv) {
    bool running = true;
    string gallows = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n" 
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";

    srand(static_cast<unsigned int>(time(0)));

    const string phrases[] = { 
            "Chris Herre", "Project One", "Gaddis 8th Edition",
            "Linux Kernel", "Dennis Ritchie" };
    // the randomized selection from the phrases array
    string randChoice = phrases[rand() % 5];
    // the array of correct guesses
    char characters[randChoice.size()];
    // set problem to a blank string of the same length as randChoice
    // we do this so problem != randChoice, but we know how many chars
    // to ask for
    string problem = getEmpty(randChoice);
    // the amount of incorrect guesses
    short incorrect = 0;
    bool contains = false;
    
    while (running)
    {
        
        // clear the screen
        system("clear");
        // the character we will guess this iteration
        char guess;
        
        cout << "Welcome to hangman by Chris H." << endl;
        // print our hangman
        cout << gallows << endl;
        // loop through all chars of randChoice string
        for (int i = 0; i < randChoice.size(); i++)
        {   
            // chapter 10 in Gaddis tolower function
            if (tolower(guess) == tolower(randChoice[i]))
            {
                char outChar = (randChoice[i] == toupper(guess) ?
                    toupper(guess) : tolower(guess));
                characters[i] = outChar;
                contains = true;
                
            }
        }
        
        if (!contains)
        {
            incorrect++;
            setGallows(gallows, incorrect);
            
            if (incorrect == 8)
            {
                cout << "Game over!" << endl;
                running = false;
                continue;
            }
        }
        contains = false;
        
        for (int j = 0; j < randChoice.size(); j++)
        {
            if (randChoice[j] == ' ')
            {
                // print 3 spaces for every space in randChoice string
                // to separate the words clearly
                cout << "   ";
            }
            // if we enter a correctly guessed char
            else if (randChoice[j] == characters[j])
            {
                // print a correctly guessed char
                cout << characters[j] << " ";
                // set char in problem string at index j to characters[j]
                problem[j] = characters[j];
            }
            else
            {
                // print blank spaces for unsolved chars
                cout << '_' << " ";
            }

        }
        
        cout << "\n\nPhrase: '" << randChoice << "'" << endl;
        cout << "\nSolved: '" << problem << "'\n" << endl;
        cout << "Enter your guess: ";
        
        // this if prevents asking for an extra input before
        // the program terminates
        if (problem != randChoice)
        {
            // ask for the next guess char
            cin >> guess;
        }
        else
        {
            cout << "\n\nYou win!!" << endl;
            running = false;
        }
    }
    return 0;
}

// returns an empty string of the same size as the problem string
string getEmpty(string s)
{
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        str = str + " ";
    }
    return str;
}

void setGallows(string& gallows, int incorrect)
{
    string gallows2 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |\n"
        "       |\n"
        "       |\n" 
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows3 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |    o\n"
        "       |    |\n"
        "       |    |\n" 
        "       |    |\n"
        "       |    |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows4 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |    o\n"
        "       |  \\ |\n"
        "       |   \\|\n" 
        "       |    |\n"
        "       |    |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows5 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |    o\n"
        "       |  \\ | /\n"
        "       |   \\|/\n" 
        "       |    |\n"
        "       |    |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows6 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |    o\n"
        "       |  \\ | /\n"
        "       |   \\|/\n" 
        "       |    |\n"
        "       |    |\n"
        "       |   / \n"
        "       |  /\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows7 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (0.0)\n"
        "       |    o\n"
        "       |  \\ | /\n"
        "       |   \\|/\n" 
        "       |    |\n"
        "       |    |\n"
        "       |   / \\\n"
        "       |  /   \\\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    string gallows8 = 
        "       _____\n"
        "       |    |\n"
        "       |    |\n"
        "       |  (X.X)\n"
        "       |    o\n"
        "       |  \\ | /\n"
        "       |   \\|/\n" 
        "       |    |\n"
        "       |    |\n"
        "       |   / \\\n"
        "       |  /   \\\n"
        "       |\n"
        "       |\n"
        "_______|_________\n";
    
    switch (incorrect)
    {
        case 1:
            gallows = gallows2;
            break;
        case 2:
            gallows = gallows3;
            break;
        case 3:
            gallows = gallows4;
            break;
        case 4:
            gallows = gallows5;
            break;
        case 5:
            gallows = gallows6;
            break;
        case 6:
            gallows = gallows7;
            break;
        case 7:
            gallows = gallows8;
            break;
            
    }
}