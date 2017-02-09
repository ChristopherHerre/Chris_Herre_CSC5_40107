
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
#include <fstream>
#include <vector>
// this library is for the sleep function used
#include <unistd.h>

using namespace std;

void start();
string getEmpty(string);
void displayTitle();
void displaySubtext();
void setContains(string, string, char [], bool&, short [], short);
void handleIncorrect(bool, string&, string, int&, bool&, char [], short [], short&);
void setCorrect(string, string&, char [], bool&);
bool alreadyGuessed(short, string, char []);
void setGallows(string&, int);
void doMenu();
void printCorrect(string , char []);

void dualSort(string names[], short sales[], int size);

int main(int argc, char** argv) {
    do
    {
        doMenu();
    } while (true);
    return 0;
}

void doMenu()
{
    char c;
    
    system("clear");
    
    // print the menu
    displayTitle();
    cout << "1) Play Hangman" << endl;
    cout << "2) Show my score" << endl;
    cout << "3) Tutorial" << endl;
    cout << "4) Close\n" << endl;
    cout << "Enter your choice: ";
    
    // prompt for choice
    cin >> c;
    cin.ignore();
    cin.clear();

    switch (c - 48)
    {
        case 1:
            // start hangman
            start();
            break;
        case 2:
            // print score, wait, then go back to menu
            //cout << "\nScore: " << score << endl;
            sleep(3);
            break;
        case 3:
            // print instructions page, wait for next input then go back to menu
            char b;
            system("clear");
            displayTitle();
            cout << "Instructions:\n\n* Solve the phrase by guessing the "
                    "characters that fill in the blanks.\n* You have 7 "
                    "attempts to solve the phrase, each wrong guess will "
                    "print part\n* of the hangman. When the hangman is "
                    "fully drawn, you lose and -10 points\n* is taken "
                    "from your score. Another -1 is taken for each wrong "
                    "guess you\n* enter. If you guess the phrase before "
                    "the hangman is fully drawn, you will\n* be awarded "
                    "12 score points." << endl;
            cout << "\nEnter b to return" << endl;
            cin >> b;
            cin.ignore();
            cin.clear();
            break;
        case 4:
            // exit the program
            exit(0);
            break;
    }
}

void start()
{
    short players;
    short activePlayer = 0;
    
    cout << "How many people are playing this round? ";
    cin >> players;
    cin.ignore();
    cin.clear();
    
    while (players < 1 || players > 4)
    {
        cout << "Error - Players must be greater than 1 and less than 4! "
                "Try again!" << endl;
        cout << "How many people are playing this round? ";
        cin >> players;
        cin.ignore();
        cin.clear();
    }
    
    vector<pair<int, string> > scoreboard(players);
    
    string names[4] = {};
    short scores[4] = {};
    
    for (int i = 0; i < players; i++)
    {
        cout << "Enter a name for player " << i + 1 << ": ";
        cin >> names[i];
        cin.ignore();
        cin.clear();
        //scoreboard[i] = make_pair(scores[i], names[i]);
    }
    
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

    // is hangman running?
    bool running = true;
    const string phrases[] = { 
            "Chris Herre", "Project Two", "Gaddis 8th Edition",
            "Linux Kernel", "Dennis Ritchie" };
    // the randomized selection from the phrases array
    string randChoice = phrases[rand() % 5];
    // the array of correct guesses
    char correct[randChoice.size()];
    // set problem to a blank string of the same length as randChoice
    // we do this so problem != randChoice, but we know how many chars
    // to ask for
    string problem = getEmpty(randChoice);
    // the amount of incorrect guesses
    int incorrect = 0;
    // does the phrase contain guess?
    bool contains = false;
    // the wrong guesses
    char wrongs[7] = {};
    // the character we will guess this iteration
    string guess = "";
    bool done = false;

    while (running)
    {   
        // this if prevents asking for an extra input before
        // the program terminates
        // if(problem == randomChoice)
        if (done)
        {
            // process game win
            ofstream outputFile;
            outputFile.open("hangman_games.txt"); 
            
            outputFile << gallows;
            outputFile.close();
            
            //score += 12;
            cout << "\n\nYou win!!" << endl;
            running = false;
            sleep(2);
        }
        else
        {
            system("clear");
            //displayTitle();
            
            cout << problem << endl;

            for (int i = 0; i < players; i++)
            {
                if (i == activePlayer)
                {
                    cout << "YOUR TURN ";
                }
                scoreboard[i] = make_pair(scores[i], names[i]);
                cout << scoreboard.at(i).second << "\t\t" << scoreboard.at(i).first << endl;
               //cout << "i: " << i << endl;
            }
            cout << gallows << endl;

            // end game due to too many incorrect guesses
            if (incorrect >= 7)
            {
                //score -= 10;
                // this stops the skipping of the last frame from visibility
                sleep(3);
                // restart
                doMenu();
                break;
            }

            // print the blank spaces yet to be solved or the solved characters
            printCorrect(randChoice, correct);
            
            cout << "\nPhrase: '" << randChoice << "'" << endl;
            cout << "\nSolved: '" << problem << "'\n" << endl;
            cout << "Enter your guess: ";
            
            
            bool valid = false;
            while(!valid) {
                // ask for the next guess char
                getline(cin,guess);
                if(guess.length() == 1) {
                    valid = true;
                }
            }
            
            // set contains to true if guess is contained within phrase
            setContains(randChoice, guess, correct, contains, scores, activePlayer);
            
            // check if we should handle an incorrect guess and handle it if needed
            handleIncorrect(contains, gallows, guess, incorrect,
                    running, wrongs, scores, activePlayer);

            setCorrect(randChoice, problem, correct, done);

            // reset flag for incorrect guess
            contains = false;

            // print our hangman

            if(++activePlayer > 4) activePlayer = 0;
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
void setContains(string randChoice, string guess, char correct[],
        bool& contains, short scores[], short activePlayer)
{
    // loop through all chars of randChoice string
    for (int i = 0; i < randChoice.size(); i++)
    {   
        // chapter 10 in Gaddis tolower function
        if (guess != "" && tolower(guess[0]) == tolower(randChoice[i]))
        {
            char outChar = (randChoice[i] == toupper(guess[0]) ?
                toupper(guess[0]) : tolower(guess[0]));
            correct[i] = outChar;
            scores[activePlayer] += 2;
            contains = true;
        }
    }
}

// check if guess is correct or not
// check if guess has already been guessed
// print box of incorrectly guessed characters
// set gallows to the next gallows frame
void handleIncorrect(bool contains, string& gallows, string guess,
        int& incorrect, bool& running, char invalids[], short scores[],
        short& activePlayer)
{
    if (!contains && guess != "")
    {
        // check if this guess has already been guessed before
        if (alreadyGuessed(incorrect, guess, invalids))
        {
            return;
        }
        
        //score -= 1;
        scores[activePlayer] -= 1;
        
        cout << "Incorrect Guesses: " << incorrect + 1 << endl;
        invalids[incorrect] = guess[0];

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
bool alreadyGuessed(short incorrect, string guess, char invalids[])
{
    bool guessed = false;
    for (int i = 0; i < incorrect; i++)
    {
        if (invalids[i] == guess[0])
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

void printCorrect(string randChoice, char correct[]) {
    for (int j = 0; j < randChoice.size(); j++)
    {
        if (randChoice[j] == ' ')
        {
            // print 3 spaces for every space in randChoice string
            // to separate the words clearly
            cout << "   ";
        }
        // if we enter a correctly guessed char
        else if (randChoice[j] == correct[j])
        {
            // print a correctly guessed char
            cout << correct[j] << " ";
            // set char in problem string at index j to correct[j]
            //problem[j] = correct[j];
        }
        else
        {
            // print blank spaces for unsolved chars
            cout << '_' << " ";
        }
    }
    cout << "\n" << endl;
}
// prints all correctly guessed characters or blank spaces
void setCorrect(string randChoice, string& problem, char correct[], bool& done)
{
    for (int j = 0; j < randChoice.size(); j++)
    {
        if (randChoice[j] == correct[j])
        {
            // set char in problem string at index j to correct[j]
            problem[j] = correct[j];
        }
    }
    if(problem == randChoice) done = true;
}


void dualSort(string names[], short sales[], int size)
{
    int startScan, maxIndex;
    string temp;
    double maxValue;
    for (startScan = 0; startScan < size - 1; startScan++)
    {
        maxIndex = startScan;
        maxValue = sales[startScan];
        temp = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (sales[index] > maxValue)
            {
                maxValue = sales[index];
                temp = names[index];
                maxIndex = index;
            }
        }
        sales[maxIndex] = sales[startScan];
        names[maxIndex] = names[startScan];
        sales[startScan] = maxValue;
        names[startScan] = temp;
    }
} 