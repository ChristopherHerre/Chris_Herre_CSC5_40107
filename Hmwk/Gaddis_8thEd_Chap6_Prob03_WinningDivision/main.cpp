
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 23, 2017, 10:34 AM
 * 
 * 3. Winning Division
 * Write a program that determines which of a company’s four divisions
 * (Northeast, Southeast, Northwest, and Southwest) had the greatest sales for
 * a quarter. It should include the following two functions, which are called
 * by main.
 * 
 * - double getSales() is passed the name of a division. It asks the user for a
 * division’s quarterly sales figure, validates the input, then returns it. It
 * should be called once for each division.
 * 
 * - void findHighest() is passed the four sales totals. It determines which is
 * the largest and prints the name of the high grossing division, along with
 * its sales figure.
 * 
 * Input Validation: Do not accept dollar amounts less than $0.00.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

float getSales(string);
void findHeighest(float totals[]);

const string DIVISIONS[] = 
    { "Northeast", "Southeast", "Northwest", "Southwest" };

int main(int argc, char** argv) {
    // create an array to store the sales of each division
    float sales[4];
    
    // set decimal format
    cout << setprecision(2) << fixed;
    
    // loop for each division name, store as variable d
    int index = 0;
    for (string d : DIVISIONS)
    {
        float s = getSales(d);
        
        // validate s
        if (s == -1)
        {
            break;
        }
        
        // assign this division its sales
        sales[index] = s;
        index++;
    }
    findHeighest(sales);
    return 0;
}

// gets the sales for a given division from the user
float getSales(string div)
{
    float sales;
    cout << "Enter the " << div << " division's quarterly sales: ";
    cin >> sales;
    
    // validate input
    if (sales < 0.00)
    {
        cout << "Sales cannot be negative!" << endl;
        return -1;
    }
    return sales;
}

// prints the highest value given an array reference
void findHeighest(float totals[])
{
    float highest = 0;
    unsigned char highIndex = 0;
    
    // set highest to the highest value in the array
    // loop through every element in the array
    for (int i = 0; i < 4; i++)
    {
        float num = totals[i];
        
        if (num > highest)
        {
            // the index of DIVISIONS that is the winner
            highIndex = i;
            highest = num;
        }
    }
    cout << "Highest grossing division: " << DIVISIONS[highIndex] << " made $"
            << highest << endl;
}