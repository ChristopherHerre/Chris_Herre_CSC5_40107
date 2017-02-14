
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 9, 2017, 11:36 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void SumTable(short [][5], short, short, int&, int&, short, short, short [],
        bool, ofstream&);
void printTable(short [][5], short, short, bool, ofstream&);

int main(int argc, char** argv)
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
    return 0;
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
            SumTable(data, rows, cols, rowsTotal, colsTotal, x, y, sums, totals, output);
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

