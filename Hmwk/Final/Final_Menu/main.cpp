
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 12, 2017, 12:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

void start();
void SumTable(short [][5], short, short, int&, int&, short, short, short [],
        bool, ofstream&);
void printTable(short [][5], short, short, bool, ofstream&);

void doProblem2();

void doProblem3();
void fillVec(vector<short>&, int, bool);
void prntVec(vector<short>, vector<short>);

void doProblem4();

void doProblem5();

int main(int argc, char** argv) {
    char c;
    
    do
    {
        cout << "2) Guess the Number" << endl;
        cout << "3) Vector Fill" << endl;
        cout << "4) Sequence Frequency" << endl;
        cout << "5) Sorting Problem" << endl;
        cout << "6) Spreadsheet Problem" << endl;
        cout << endl;
        cout << "Select an option: ";
        cin >> c;
        system("clear");
        switch (c - 48)
        {
            case 2:
                doProblem2();
                cout << endl;
                break;
            case 3:
                doProblem3();
                cout << endl;
                break;
            case 4:
                doProblem4();
                cout << endl;
                break;
            case 5:
                doProblem5();
                cout << endl;
                break;
            case 6:
                start();
                cout << endl;
                break;
        }
    } while (c - 48 > 0 && c - 48 < 10);
    return 0;
}

void start()
{
    const short rows = 6;
    const short cols = 5;
    short data[rows][cols];
    
    short val;
    ifstream file;
    file.open("table.dat");
    
    ofstream output;
    output.open("augtable.dat");
    
    // read table.dat file and assign data[x][y] the next value
    // in the file
    if (file.is_open())
    {
        for (int y = 0; y < cols; y++)
        {
            for (int x = 0; x < rows; x++)
            {
                file >> val;
                data[x][y] = val;
            }
        }
    }
    file.close();
    
    // display the original table
    printTable(data, rows, cols, false, output);
    cout << endl;
    // display the summed table
    printTable(data, rows, cols, true, output);
}

void printTable(short data[][5], short rows, short cols, bool totals,
        ofstream& output)
{
    if (totals)
    {
        rows += 1;
        cols += 1;
    }
    
    int colsTotal = 0;
    // the sums of the rows
    short sums[5];
    
    for (int y = 0; y < cols; y++)
    {
        int rowsTotal = 0;
        
        for (int x = 0; x < rows; x++)
        {  
            SumTable(data, rows, cols, rowsTotal, colsTotal, x, y, sums, totals,
                    output);
        }
        cout << endl;
        output << endl;
    }
}

// sums and displays the rows and columns of the original table
void SumTable(short data[][5], short rows, short cols, int& rowsTotal,
        int& colsTotal, short x, short y, short sums[], bool totals,
        ofstream& output)
{
    if (x <= 5 && y <= 4)
    {
        // display the original data
        cout << setw(6) << right << data[x][y];
        output << setw(6) << right << data[x][y];
        if (totals)
            // add up the totals
            rowsTotal += data[x][y];
    }
    else if (x == 6)
    {
        // displays the very last value only
        if (y == 5)
        {
            // the sum of sums
            int sum = 0;
            for (int i = 0; i < 5; i++)
            {
                sum += sums[i];
            }
            cout << setw(6) << sum;
            output << setw(6) << sum;
            return;
        }
        // displays the row totals
        cout << setw(6) << rowsTotal;
        output << setw(6) << rowsTotal;
        // store the row total to be summed
        sums[y] = rowsTotal;
        // reset rowsTotal for the next row
        rowsTotal = 0;
    }
    // if last row
    else if (y == 5)
    {
        // sum all columns
        colsTotal += data[x][0];
        colsTotal += data[x][1];
        colsTotal += data[x][2];
        colsTotal += data[x][3];
        colsTotal += data[x][4];
        cout << setw(6) << colsTotal;
        output << setw(6) << colsTotal;
        colsTotal = 0;
    }
}

void doProblem2()
{
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
}

void doProblem3()
{
    vector<short> even;
    vector<short> odd;
    // the vector size input from the user
    int size;
    
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // prompt the user to input size value
    cout << "Enter the size of the even and odds vectors: ";
    cin >> size;
    
    // fill a vector with random even numbers
    fillVec(even, size, true);
    // fill a vector with random odd numbers
    fillVec(odd, size, false);
    
    //display the table of even and odd vectors
    cout << "Even\tOdd" << endl;
    prntVec(even, odd);
}

void doProblem4()
{
    // the sequence of numbers
    short numbers[] = { 9, 52, 78, 101, 119 };
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    // the frequency variables for each number in the sequence
    // initialize all to 0
    int freq[5] = {};
    
    for (int i = 0; i < 10000; i++)
    {
        // select a random choice from the sequence
        short choice = numbers[rand() % 5];
        // count up the occurances and store them
        switch (choice)
        {
            case 9:
                freq[0]++;
                break;
            case 52:
                freq[1]++;
                break;
            case 78:
                freq[2]++;
                break;
            case 101:
                freq[3]++;
                break;
            case 119:
                freq[4]++;
                break;
        }
    }
    
    // display the occurances
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
            case 0:
                cout << "9 occured ";
                break;
            case 1:
                cout << "52 occured ";
                break;
            case 2:
                cout << "78 occured ";
                break;
            case 3:
                cout << "101 occured ";
                break;
            case 4:
                cout << "119 occured ";
                break;
        }
        cout << freq[i];
        cout << " times." << endl;
        
    }
}

void doProblem5()
{
    // store the file data in a string s
    string s;
    vector<string> vec;
    // the input file
    ifstream file;
    file.open("input.dat");
    // the next read char
    char c;
    
    if (file.is_open())
    {
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 15; x++)
            {
                // read the next character of the file
                file >> c;
                s = s + c;
                cout << c;
                
            }
            
            s = s + "\n";
            // store the strings in the vector
            vec.push_back(s);
            cout << endl;
        }
    }
    // close the input file
    file.close();
    
    cout << endl;

    // i couldn't get the sorting working correctly.
    // this is what i had so far
    for (int i = 0; i < 10 - 1; i++)
    {
        if (vec[i][0] > vec[i + 1][0])
        {
            string temp = vec.at(i);
            cout << temp << endl;
            vec.at(i) = vec.at(i + 1);
            vec.at(i + 1) = temp;
        }
    }
}

// prints a table of even and odd vectors
void prntVec(vector<short> even, vector<short> odd)
{
    for (int i = 0; i < even.size(); i++)
    {
        cout << even[i] << "\t" << odd[i] << endl;
    }
}

// populates a vector with random values
// if even is true, the values will only be even values
// if even is false, only odd values
void fillVec(vector<short>& vec, int size, bool even)
{
    for (int i = 0; i < size; i++)
    {
        short num = rand() % 99;
        if (even && num % 2 != 0)
        {
            num += 1;
        }
        else if (!even && num % 2 == 0)
        {
            num -= 1;
        }
        vec.push_back(num);
    }
}
