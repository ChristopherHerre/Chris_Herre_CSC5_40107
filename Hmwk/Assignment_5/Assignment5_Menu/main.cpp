
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 1, 2017, 1:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

void displayMenu();

void markup();
float calculateRetail(float, float);

void winningDivision();
float getSales(string);
void findHeighest(float totals[]);

void safestDrivingArea();
int getNumAccidents(string);
void findLowest(short []);

const string REGIONS[] = { "north", "south", "east", "west", "central" };

const string DIVISIONS[] = 
    { "Northeast", "Southeast", "Northwest", "Southwest" };

int main(int argc, char** argv) {
    short choice;
    
    do
    {   
        displayMenu();
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                markup();
                break;
            case 2:
                winningDivision();
                break;
            case 3:
                safestDrivingArea();
                break;
        }
    } while (choice > 0 && choice <= 10);
    return 0;
}

void displayMenu()
{
    cout << "Welcome to Chris Herre's Assignment 5 Menu!\n" << endl;
    cout << "1) Markup" << endl;
    cout << "2) Winning Division" << endl;
    cout << "3) Safest Driving Area" << endl;
    cout << "4) Falling Distance" << endl;
    cout << "5) Kinetic Energy" << endl;
    cout << "6) Celsius Table" << endl;
    cout << "7) Coin Toss" << endl;
    cout << "8) Present Value" << endl;
    cout << "9) Future Value" << endl;
    cout << "10) Population" << endl;
}

void markup()
{
    float cost, markup;
    cout << fixed << setprecision(2);
    cout << "Enter an item's wholesale cost: ";
    cin >> cost;
    
    // check if cost is negative
    if (cost < 0)
    {
        cout << "Wholesale cost cannot be negative!" << endl;
        // exit early
        return;
    }
    
    cout << "Enter the markup percentage (Ex: 50% = 0.5): ";
    cin >> markup;
    
    // check if markup is negative
    if (markup < 0)
    {
        cout << "Markup percentage cannot be negative!" << endl;
        // exit early
        return;
    }
    
    cout << "Retail price = $" << calculateRetail(cost, markup) << endl;
}

// returns the retail price given cost and markup
float calculateRetail(float cost, float markup)
{
    return cost + (cost * markup);
}

void winningDivision()
{
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

void safestDrivingArea()
{
    short numAccidents[5];

    // populate numAccidents array with the return value of getNumAccidents
    // for each region
    for (int i = 0; i < 5; i++)
    {
        numAccidents[i] = getNumAccidents(REGIONS[i]);
    }
    // call findLowest function
    findLowest(numAccidents);    
}

int getNumAccidents(string region)
{
    short accidents;
    
    // prompt user to input the number of accidents for the given region
    cout << "What is the number of automobile accidents in the " << region
            << " region? ";
    cin >> accidents;
    
    // validate input, cannot be negative # of accidents
    if (accidents < 0)
    {
        cout << "Cannot accept an accident number less than 0!" << endl;
        return -1;
    }
    return accidents;
}

void findLowest(short accidents[])
{
    // set lowest to a value larger than any inputs to the accidents array
    short lowest = 30000;
    unsigned char lowestIndex = 0;
    
    // loop for each index in our regions array
    for (int i = 0; i < 5; i++)
    {
        if (accidents[i] < lowest)
        {
            lowestIndex = i;
            // reassign lowest to the actual lowest value so far
            // through the loop
            lowest = accidents[i];
        }
    }
    // output which region had the least accidents
    cout << "The " << REGIONS[lowestIndex] << " region had the least amount of"
            " accidents at " << lowest << " accidents last year." << endl;
}