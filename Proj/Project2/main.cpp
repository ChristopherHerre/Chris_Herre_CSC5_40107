
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

void start();
string getEmpty(string);
void displayTitle();
void setContains(string, char, char [], bool&);
void handleIncorrect(bool, string&, char, int&, bool&, char []);
void printProgress(string, string, char []);
bool alreadyGuessed(short, char, char []);
void setGallows(string&, int);

int main(int argc, char** argv) {
    start();
    return 0;
}

void start()
{
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

    bool running = true;
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
    int incorrect = 0;
    bool contains = false;
    char wrongs[7] = {};
    // the character we will guess this iteration
    char guess = '\0';
    
    while (running)
    {   
        displayTitle();
        // set contains to true if guess is contained within phrase
        setContains(randChoice, guess, characters, contains);
        
        // check if we should handle an incorrect guess and handle it if needed
        handleIncorrect(contains, gallows, guess, incorrect,
                running, wrongs);
        // reset flag for incorrect guess
        contains = false;
        
        // print our hangman
        cout << gallows << endl;
        
        // end game due to too many incorrect guesses
        if (incorrect >= 7)
        {
            // restart
            start();
            break;
        }
        
        printProgress(randChoice, problem, characters);
        
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

// displays the title and clears the screen
void displayTitle()
{
    string hangman = " /$$   /$$\n"                   
    "| $$  | $$\n"                                                                
    "| $$  | $$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$$\n" 
    "| $$$$$$$$ |____  $$| $$__  $$ /$$__  $$| $$_  $$_  $$ |____  $$| $$__  $$\n"
    "| $$__  $$  /$$$$$$$| $$  \\ $$| $$  \\ $$| $$ \\ $$ \\ $$  /$$$$$$$| $$  \\ $$\n"
    "| $$  | $$ /$$__  $$| $$  | $$| $$  | $$| $$ | $$ | $$ /$$__  $$| $$  | $$\n"
    "| $$  | $$|  $$$$$$$| $$  | $$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$| $$  | $$\n"
    "|__/  |__/ \\_______/|__/  |__/ \\____  $$|__/ |__/ |__/ \\_______/|__/  |__/\n"
    "                               /$$  \\ $$                                  \n"
    "                              |  $$$$$$/                                   \n"
    "                               \\______/                                    \n";
    // clear the screen
    system("clear");
    cout << hangman << endl;
}

// sets contains to true if guess is contained within randChoice
void setContains(string randChoice, char guess, char characters[],
        bool& contains)
{
    // loop through all chars of randChoice string
    for (int i = 0; i < randChoice.size(); i++)
    {   
        // chapter 10 in Gaddis tolower function
        if (guess != '\0' && tolower(guess) == tolower(randChoice[i]))
        {
            char outChar = (randChoice[i] == toupper(guess) ?
                toupper(guess) : tolower(guess));
            characters[i] = outChar;
            contains = true;
        }
    }
}

// check if guess is correct or not
// check if guess has already been guessed
// print box of incorrectly guessed characters
// set gallows to the next gallows frame
void handleIncorrect(bool contains, string& gallows, char guess,
        int& incorrect, bool& running, char invalids[])
{
    if (!contains && guess != 0)
    {
        // check if this guess has already been guessed before
        if (alreadyGuessed(incorrect, guess, invalids))
        {
            return;
        }

        cout << "Incorrect Guesses: " << incorrect + 1 << endl;
        invalids[incorrect] = guess;

        cout << "#################\n# ";
        for (int i = 0; i < 7; i++)
        {
            cout << (invalids[i] > 0 ? invalids[i] : '_') << " ";
        }
        cout << "#\n#################\n" << endl;

        if (incorrect == 7)
        {
            running = false;
            return;
        }
        incorrect++;
        setGallows(gallows, incorrect);
    }
}

// returns true if guess was guessed before
bool alreadyGuessed(short incorrect, char guess, char invalids[])
{
    bool guessed = false;
    for (int i = 0; i < incorrect; i++)
    {
        if (invalids[i] == guess)
        {
            guessed = true;
        }
    }
    return guessed;
}

// sets the gallows string to the next frame
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

// prints all correctly guessed characters or blank spaces
void printProgress(string randChoice, string problem, char characters[])
{
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
}