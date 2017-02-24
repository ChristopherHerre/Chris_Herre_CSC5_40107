/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on February 24, 2017, 1:45 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printMenu();
void doProb312();
void doProb313();
void doProb410();
void doProb67();
float celsius(float);
void doProb46();
void doProb45();
void doProb511();
void bubbleSort(string [], short);
int binarySearch(string [], int, string);
void doProb87();
void doProb75();

const float YEN_PER_DOLLAR = 113.26f;
const float EUROS_PER_DOLLAR = 0.95f;

int main(int argc, char** argv) {
    char c;
    
    do
    {
        printMenu();
        cin >> c;
        
        switch (c - 48)
        {
            case 1:
                doProb312();
                break;
            case 2:
                doProb313();
                break;
            case 3:
                doProb45();
                break;  
            case 4:
                doProb46();
                break;   
            case 5:
                doProb410();
                break;
            case 6:
                doProb511();
                break;
            case 7:
                doProb67();
                break;
            case 8:
                doProb75();
                break;
            case 9:
                doProb87();
                break;

        }
    } while (c - 48 > 0 && c - 48 <= 10);
    return 0;
}

void printMenu()
{
    //system("clear");
    cout << "1) Chapter 3 Problem 12" << endl;
    cout << "2) Chapter 3 Problem 13" << endl;
    cout << "3) Chapter 4 Problem 5" << endl;
    cout << "4) Chapter 4 Problem 6" << endl;
    cout << "5) Chapter 4 Problem 10" << endl;
    cout << "6) Chapter 5 Problem 11" << endl;
    cout << "7) Chapter 6 Problem 7" << endl;
    cout << "8) Chapter 7 Problem 5" << endl;
    cout << "9) Chapter 8 Problem 7" << endl;
    cout << "Select an option: ";
}

// chapter 3 problem 12
void doProb312()
{
    float cel;
    
    cout << "Note: Enter 1000000 to return to the main menu." << endl;
    
    do
    {
        // prompt for the celsius temp
        cout << "Enter a Celsius temperature: ";
        cin >> cel;

        // print the fahrenheit temp
        cout << cel << " Celsius converted to Fahrenheit is " << 1.8 * cel + 32
                << "." << endl;
    // end the loop if the input is greater than a million
    } while (cel < 1000000);
}

void doProb313()
{
    float usd;
    
    cout << "Note: Enter -1 to return to the main menu." << endl;
    
    do
    {
        cout << showpoint << fixed << setprecision(2);
        cout << "Enter a U.S. dollar amount: ";
        cin >> usd;
        cout << usd << " USD is " << usd * YEN_PER_DOLLAR << " Yen." << endl;
        cout << usd << " USD is " << usd * EUROS_PER_DOLLAR << " Euros." << endl;
    } while (usd != -1);
}

void doProb410()
{
    short month, year, numDays;
    
    cout << "Note: Enter a month out of the bounds of 1-12 to return to main menu." << endl;
    
    do
    {
        cout << "Enter a month (1-12): ";
        cin >> month;
        cout << "Enter a year: ";
        cin >> year;

        switch (month)
        {
            case 1:
                numDays = 31;
                break;
            case 2:
            {
                bool leap = false;
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        leap == true;
                    }
                }
                else
                {
                    if (year % 4 == 0)
                    {
                        leap = true;
                    }
                }
                numDays = leap ? 29 : 28;
            }
            break;
            case 3:
                numDays = 31;
                break;
            case 4:
                numDays = 30;
                break;
            case 5:
                numDays = 31;
                break;
            case 6:
                numDays = 30;
                break;
            case 7:
                numDays = 31;
                break;
            case 8:
                numDays = 31;
                break;
            case 9:
                numDays = 30;
                break;
            case 10:
                numDays = 31;
                break;
            case 11:
                numDays = 30;
                break;
            case 12:
                numDays = 31;
                break;
            default:
                numDays = -1;
        }
        cout << numDays << " days" << endl;
    } while (month > 0 && month <= 12);
}

void doProb67()
{
    for (int i = 0; i <= 20; i++)
    {
        cout << i << " Fahrenheit\t=\t" << celsius(i) << " Celsius" << endl;
    }
}

float celsius(float fahr)
{
    return 5/9.0 * (fahr - 32);
}

void doProb46()
{
    float mass, weight;
    
    // prompt user for mass input
    cout << "Enter an object's mass in kg: ";
    cin >> mass;
    
    // convert mass to Newtons
    weight = mass * 9.8;
    
    // check if object is too heavy
    if (weight > 1000)
    {
        cout << "This object is too heavy." << endl;
        return;
    }
    // check if object is too light
    else if (weight < 10)
    {
        cout << "This object is too light." << endl;
        return;
    }
    
    // finally, output the conversion
    cout << mass << "kg = " << weight << " newtons." << endl;
}

void doProb45()
{
    float weight, height, bmi;
    
    // prompt user to input values
    cout << "Enter the person's weight in pounds: ";
    cin >> weight;
    
    cout << "Enter the person's height in inches: ";
    cin >> height;
    
    // calc bmi
    bmi = weight * 700 / (height * height);
    
    cout << "BMI=" << bmi << endl;
    
    // check if person is underweight
    if (bmi < 18.5)
    {
        cout << "This person is underweight." << endl;
    }
        short days;
    float nOrganisms = 0, popIncrease;
    
    // prompt user to enter a starting number of organisms
    cout << "Enter the starting number of organisms: ";
    cin >> nOrganisms;
    
    // check if starting number is less than or equal to 2
    if (nOrganisms <= 2)
    {
        cout << "The starting number of organisms must be greater than 2!"
                << endl;
        return;
    }
    
    // prompt user to enter the population increase percentage
    cout << "What is the population increase percentage?: ";
    cin >> popIncrease;
    
    // check if percentage is less than or equal to 0
    if (popIncrease <= 0)
    {
        cout << "Population increase percentage must be a positive number!" << endl;
        return;
    }
    
    // prompt the user to enter number of days the organisms will multiply for
    cout << "How many days will the organisms multiply for? ";
    cin >> days;
    
    // days cannot be less than 1
    if (days < 1)
    {
        cout << "Days cannot be less than 1!" << endl;
        return;
    }
    
    // loop as many times as the value of days
    for (int i = 1; i <= days; i++)
    {
        // increase population size by the percentage of population increase
        nOrganisms += nOrganisms * popIncrease;
        cout << "Day " << i << ": Population is " << nOrganisms << endl;
}
    // check if person is in the optimal weight range
    if (bmi >= 18.5 && bmi < 25)
    {
        cout << "This person has optimal weight for their given height."
                << endl;
    }
    
    // check if the person is overweight
    if (bmi > 25)
    {
        cout << "This person is overweight." << endl;
    }
}

void doProb511()
{
    short days;
    float nOrganisms = 0, popIncrease;
    
    // prompt user to enter a starting number of organisms
    cout << "Enter the starting number of organisms: ";
    cin >> nOrganisms;
    
    // check if starting number is less than or equal to 2
    if (nOrganisms <= 2)
    {
        cout << "The starting number of organisms must be greater than 2!"
                << endl;
        return;
    }
    
    // prompt user to enter the population increase percentage
    cout << "What is the population increase percentage?: ";
    cin >> popIncrease;
    
    // check if percentage is less than or equal to 0
    if (popIncrease <= 0)
    {
        cout << "Population increase percentage must be a positive number!" << endl;
        return;
    }
    
    // prompt the user to enter number of days the organisms will multiply for
    cout << "How many days will the organisms multiply for? ";
    cin >> days;
    
    // days cannot be less than 1
    if (days < 1)
    {
        cout << "Days cannot be less than 1!" << endl;
        return;
    }
    
    // loop as many times as the value of days
    for (int i = 1; i <= days; i++)
    {
        // increase population size by the percentage of population increase
        nOrganisms += nOrganisms * popIncrease;
        cout << "Day " << i << ": Population is " << nOrganisms << endl;
    }
}

// swaps elements in the array into alphabetical order
// swap by first letter
void bubbleSort(string names[], short size)
{
    bool swap;
    string temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (names[i][0] > names[i + 1][0])
            {
                temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                swap = true;
            }
        }
    }  while (swap);
    cout << "finished bubble sort" << endl;
}

// 
int binarySearch(string names[], int numElems, string value)
{
    int first = 0, last = numElems - 1, middle, position = -1;
    bool found = false;
    
    cout << "starting binary search" << endl;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (names[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (names[middle][0] > value[0])
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}

void doProb87()
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
        "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth" };
    // Insert your code to complete this program
    
    // sort the strings by first letter before we do the binary search
    bubbleSort(names, NUM_NAMES);
    
    // print each string in the names array
    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }
    
    cout << endl;
    
    // set the default name
    string name = "Weaver, Jim";
    
    do
    {
        // prompt for a name value
        cout << "Enter a name typed exactly like one of the names in the array: ";
        // overwrite name with the users input
        getline(cin, name);

        // find the index of name
        int i = binarySearch(names, NUM_NAMES, name);
        cout << name << " is located at index " << i << "." << endl;
    } while (true);
}

void doProb75()
{
    // an array for 5 days worth of data for 3 monkeys
    int poundsEaten[3][5];
    // the total pounds eaten by all monkeys
    int totalEaten = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // prompt user to input pounds eaten by each money
            // for each of 5 days
            cout << "How many pounds were eaten by monkey " << i + 1
                    << " on day " << j + 1 << "? ";
            cin >> poundsEaten[i][j];
            
            // validate poundsEaten[i][j]
            while (poundsEaten[i][j] < 1)
            {
                cout << "Error - Pounds eaten cannot be negative! Try again."
                        << endl;
                cout << "How many pounds were eaten by monkey " << i + 1
                        << " on day " << j + 1 << "? ";
                cin >> poundsEaten[i][j]; 
            }
            // add this input to our total
            totalEaten += poundsEaten[i][j];
        }
    }
    
    int lowest = poundsEaten[0][0], highest = poundsEaten[0][0];
   
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 5; j++)
        {
            // store the lowest value so far in the loop
            if (poundsEaten[i][j] < lowest)
            {
                lowest = poundsEaten[i][j];
            }
            // store the highest value so far in the loop
            else if (poundsEaten[i][j] > highest)
            {
                highest = poundsEaten[i][j];
            }
        }
    }
    
    // print lowest / highest
    cout << "Lowest: " << lowest << "\nHighest: " << highest << endl;
    // print average
    cout << "Average food eaten per day by whole family of monkeys: "
            << totalEaten / 5;
}