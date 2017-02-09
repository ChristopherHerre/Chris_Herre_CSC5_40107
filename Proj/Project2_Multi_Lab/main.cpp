
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
#include <iomanip>
#include <ctime>
// this library is for the sleep function used
#include <unistd.h>

using namespace std;

void start();
string getEmpty(string);
void displayTitle();
void displaySubtext();
void setContains(string, string, char [], bool&, short [], short);
void handleIncorrect(bool, string&, string, int&, bool&, char [], short [],
        short&);
void setProblem(string, string&, char [], bool&);
bool alreadyGuessed(short, string, char []);
void setGallows(string&, int);
void doMenu();
void printCorrect(string , char []);
void showLastGame();
void outputToFile(vector<pair<int, string> >, short);
void setPlayers(short&, string []);
void handleWin(vector<pair<int, string> >, short, string [], bool&);
void printScoreboard(vector<pair<int, string> > &, short, short, short [],
        string []);
void handleUserInput(string&, string&, string,
        string, char [], char [], short [],
        short&, int&, short&, bool&,
        bool&, bool&);
void sort(vector<pair<int, string> > &, short);

int main(int argc, char** argv)
{
    doMenu();
    return 0;
}

void doMenu()
{
    char c;
    
    do
    {
        system("clear");

        // print the menu
        displayTitle();
        cout << "1) Play Hangman" << endl;
        cout << "2) Show Last Game" << endl;
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
                cout << "Results are bubble sorted from greatest to least:"
                        << endl;
                showLastGame();
                break;
            case 3:
                // print instructions page, wait for next input then go
                // back to menu
                char b;
                system("clear");
                displayTitle();
                cout << "Instructions:\n\n* Solve the phrase by guessing the "
                        "characters that fill in the blanks.\n* You have 7 "
                        "attempts to solve the phrase, each wrong guess will "
                        "print part\n\tof the hangman.\n* If the hangman is "
                        "fully drawn, there is no winner. The player with the "
                        "most\n\tpoints when the phrase is solved is the winner "
                        "otherwise.\n* Correct guesses are +2 points, wrong "
                        "guesses are -1." << endl;
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
    } while (c - 48 > 0 && c - 48 < 5);
}

void start()
{
    short players;
    short activePlayer = 0;
    string names[4] = {};
    short scores[4] = {};
    
    setPlayers(players, names);
    vector<pair<int, string> > scoreboard(players);
    
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
    bool won = false;

    while (running)
    {   
        if (won)
        {
            handleWin(scoreboard, players, names, running);
        }
        // if we have not yet won
        else
        {
            system("clear");

            printScoreboard(scoreboard, players, activePlayer, scores, names);
            // print our hangman
            cout << gallows << endl;

            // end game due to too many incorrect guesses
            if (incorrect >= 7)
            {
                outputToFile(scoreboard, players);
                //score -= 10;
                // this stops the skipping of the last frame from visibility
                sleep(3);
                // restart
                doMenu();
                break;
            }

            // print the blank spaces yet to be solved or the solved characters
            printCorrect(randChoice, correct);
            
            //cout << "\nPhrase: '" << randChoice << "'" << endl;
            //cout << "\nSolved: '" << problem << "'\n" << endl;
            cout << "Enter your guess: ";
            
            handleUserInput(gallows, guess, randChoice, problem, correct,
                    wrongs, scores, activePlayer, incorrect, players, contains,
                    running, won);
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
        sleep(2);
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

void setProblem(string randChoice, string& problem, char correct[], bool& won)
{
    for (int j = 0; j < randChoice.size(); j++)
    {
        if (randChoice[j] == correct[j])
        {
            // set char in problem string at index j to correct[j]
            problem[j] = correct[j];
        }
    }
    // if problem == randChoice, someone has won
    if (problem == randChoice) 
    {
        won = true;
    }
}

void showLastGame()
{
    // print score, wait, then go back to menu
    string line;
    ifstream file ("hangman_games.txt");
    
    if (file.is_open())
    {
        while (getline (file, line))
        {
            cout << line << '\n';
        }
        file.close();
    }
    sleep(3);
}

// notice: vector is passed by value!
void outputToFile(vector<pair<int, string> > scoreboard, short players)
{
    sort(scoreboard, players);
    ofstream outputFile;
    outputFile.open("hangman_games.txt"); 

    for (int i = 0; i < players; i++)
    {
        outputFile << left << setw(12) << scoreboard.at(i).second << setw(15)
                << right << scoreboard.at(i).first << "\n";
    }
    outputFile.close();
}

// ask the user how many players are playing
// set the players variable to this number
// validate the input
void setPlayers(short& players, string names[])
{
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
    
    for (int i = 0; i < players; i++)
    {
        cout << "Enter a name for player " << i + 1 << ": ";
        cin >> names[i];
        cin.ignore();
        cin.clear();
    }
}

// notice: vector is passed by value!
void handleWin(vector<pair<int, string> > scoreboard, short players,
        string names[], bool& running)
{
    // output to file
    outputToFile(scoreboard, players);

    string name;
    short highest = 0;

    // find the name of the winner
    for (int i = 0; i < players; i++)
    {
        if (scoreboard.at(i).first > highest)
        {
            name = names[i];
            highest = scoreboard.at(i).first;
        }
    }

    cout << "\n\n" << name  << " is the winner!" << endl;
    running = false;
    sleep(2);
}

// prints the usernames, scores, and whos turn it is
// sets the scoreboard indexes for each player
void printScoreboard(vector<pair<int, string> > &scoreboard, short players,
        short activePlayer, short scores[], string names[])
{
    for (int i = 0; i < players; i++)
    {
        if (i == activePlayer)
        {
            cout << "YOUR TURN ";
        }
        scoreboard[i] = make_pair(scores[i], names[i]);

        cout << left << setw(12) << scoreboard.at(i).second << setw(15)
                << right << scoreboard.at(i).first << endl;
    }
}

// take the users input and validate it
// see if guess is contained in phrase, handle that
// see if guess is incorrect, handle that
// set the problem to apply the new character guessed
// next players turn
void handleUserInput(string& gallows, string& guess, string randChoice,
        string problem, char correct[], char wrongs[], short scores[],
        short& activePlayer, int& incorrect, short& players, bool& contains,
        bool& running, bool& won)
{
    //get user input, make sure its length is 1
    bool valid = false;
    while (!valid)
    {
        // ask for the next guess char
        getline(cin, guess);

        if (guess.length() == 1)
        {
            valid = true;
        }
    }

    // set contains to true if guess is contained within phrase
    setContains(randChoice, guess, correct, contains, scores, activePlayer);
    cout << endl;
    // check if we should handle an incorrect guess and handle it if needed
    handleIncorrect(contains, gallows, guess, incorrect,
            running, wrongs, scores, activePlayer);
    // reset flag for incorrect guess
    contains = false;

    setProblem(randChoice, problem, correct, won);

    if (++activePlayer > players - 1)
    {
        activePlayer = 0;
    }
}

// bubble sort the vector
void sort(vector<pair<int, string> > &scoreboard, short players)
{
    bool swap;
    short temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < players - 1; i++)
        {
            if (scoreboard[i].first < scoreboard[i + 1].first)
            {
                temp = scoreboard.at(i + 1).first;
                scoreboard[i + 1].first = scoreboard[i].first;
                scoreboard[i].first = temp;
                swap = true;
            }
        }
    } while (swap);
} 