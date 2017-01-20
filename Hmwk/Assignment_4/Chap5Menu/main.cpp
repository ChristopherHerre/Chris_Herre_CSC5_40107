
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 19, 2017, 10:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void sumOfNumbers();
void oceanLevels();
void caloriesBurned();
void membershipFee();
void distanceTraveled();
void pennies();
void hotelOccupancy();
void population();
void salesChart();

int main(int argc, char** argv) {
    char choice;
    
    do
    {
        cout << "Choose from the list" << endl;
        cout << "Type 1 for Sum of Numbers Problem" << endl;
        cout << "Type 2 for Ocean Levels Problem" << endl;
        cout << "Type 3 for Calories Burned Problem" << endl;
        cout << "Type 4 for Membership Fee Problem" << endl;
        cout << "Type 5 for Distance Traveled Problem" << endl;
        cout << "Type 6 for Pennies For Pay Problem" << endl;
        cout << "Type 7 for Hotel Occupancy Problem" << endl;
        cout << "Type 8 for Population Problem" << endl;
        cout << "Type 9 for Sales Bar Chart Problem" << endl;

        cin >> choice;

        switch (choice)
        {
            case '1':
                sumOfNumbers();
                break;
            case '2':
                oceanLevels();
                break;
            case '3':
                caloriesBurned();
                break;
            case '4':
                membershipFee();
                break;
            case '5':
                distanceTraveled();
                break;
            case '6':
                pennies();
                break;
            case '7':
                hotelOccupancy();
                break;
            case '8':
                population();
                break;
            case '9':
                salesChart();
                break;              
        }
    } while (choice >= '1' && choice <= '9');
    
    return 0;
}

void sumOfNumbers()
{
    float input = 0, sum = 0;
    // prompt user to input a number
    cout << "Enter a positive integer value: ";
    cin >> input;

    // if number is negative
    if (input < 0)
    {
        cout << "Input cannot be negative!" << endl;
        // exit program
        return;
    }

    // go through all numbers between 1 and the input number
    for (float i = 1.0; i <= input; i++)
    {
        // add i to sum
        sum += i; 
        cout << "Adding " << i << " to sum." << endl;
    }

    // print sum
    cout << "Sum =\t" << sum << endl;
}

void oceanLevels()
{
    // left justify year
    // display labels
    cout << left << setw(8) << "Year"  << "Amount risen (in mm)" << endl;
    
    // loop 25 times
    for (int yearOffset = 0; yearOffset <= 25; yearOffset++)
    {
        // format our numbers to 2 digits after the decimal
        cout << setprecision(2) << fixed;
        
        // calc the amount risen per year
        float risen = yearOffset * 1.5;
        // display + or a blank space depending on if risen is positive
        cout << setw(8) << 2017 + yearOffset << (risen <= 0 ? " " : "+") << risen << endl;
    }
}

void caloriesBurned()
{
    cout << "You are running on a treadmill . . ." << endl;

    // start at 5, loop till i = 30
    for (int i = 5; i <= 30; i += 5)
    {
        // do the conversion and output results
        cout << "Its been " << i << " minutes. You have burned " << i * 3.6 << " calories so far." << endl;
    }
}

void membershipFee()
{
    float charge = 2500;
    
    // set format to two digits after the decimal
    cout << setprecision(2) << fixed;
    
    // loop 6 times
    for (int year = 0; year < 6; year++)
    {
        // print the current price and the raised price
        cout << "Year " << year + 1 << " - Current price $" << charge << " will go up to $";
        // calc the raised price
        charge += charge * 0.06;
        cout << charge << "." << endl;
    }
}

void distanceTraveled()
{
    float speed, hours;
    
    // prompt user to input speed
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    
    // check if speed is negative
    if (speed < 0)
    {
        cout << "Speed cannot be negative!" << endl;
        return;
    }
    
    // prompt user to input hours
    cout << "How many hours has it traveled? ";
    cin >> hours;
    
    // hours cannot be less than 1
    if (hours < 1)
    {
        cout << "Time traveled cannot be less than 1!" << endl;
        return;
    }
    
    // display table
    cout << "Hour\tDistance Traveled\n--------------------------------" << endl;
    
    // display distance traveled for each hour
    for (int i = 1; i <= hours; i++)
    {
        cout << i << "\t" << speed * i << endl;
    }
}

void pennies()
{
    short days;
    // the user might want to know their pay after a year, so we need a double
    double pay = 0.01, sum = 0;
    
    // set format to two digits after decimal
    cout << setprecision(2) << fixed;
    
    // explain to user what program does
    cout << "This program will calculate a person's salary over time at 0.01"
            " per day, doubling daily.\n" << endl;
    // prompt for days worked        
    cout << "How many days has the person worked? ";
    cin >> days;
    
    // loop for every day
    for (int i = 1; i <= days; i++)
    {
        cout << "Day " << i << ": " << pay << endl;
        // add pay to sum
        sum += pay;
        // double pay
        pay *= 2;
    }
    
    // finally, print the total
    cout << "Salary: " << sum << endl;
}

void hotelOccupancy()
{
    short floors, totalRooms = 0, totalOccupied = 0;
    
    // set format for decimal numbers
    cout << fixed << setprecision(2);
    // prompt the user to enter the number of floors
    cout << "How many floors does the hotel have? ";
    cin >> floors;
    
    if (floors < 1)
    {
        // there must be at least one floor
        cout << "Floors cannot be less than 1!" << endl;
        return;
    }
    
    for (int i = 1; i <= floors; i++)
    {
        // skip floor 13
        if (i == 13)
        {
            cout << ". . . Skipping the 13th floor . . . " << endl;
            continue;
        }
        
        short rooms, occupied;
        
        // prompt user to enter the rooms on this floor
        cout << "How many rooms are on floor " << i << "? ";
        cin >> rooms;
        // add rooms to totalRooms
        totalRooms += rooms;
        
        // check if the rooms on the floor is less than 10
        if (rooms < 10)
        {
            cout << "There should be at least 10 rooms per floor!" << endl;
            break;
        }
        
        cout << "How many rooms are occupied on this floor? ";
        cin >> occupied;
        
        // check if occupied rooms is greater than the number of rooms on
        // this floor. That would make no sense.
        if (occupied > rooms)
        {
            cout << "Rooms occupied cannot be greater than the total number of"
                    " rooms on this floor." << endl;
            break;
        }
        
        // add occupied to totalOccupied
        totalOccupied += occupied;
    }
    
    // display total rooms in the hotel, and how many are occupied
    cout << "Total rooms: " << totalRooms << " totalOccupied: " << totalOccupied
            << " totalUnoccupied: " << totalRooms - totalOccupied << endl;
    // cast totalOccupied and totalRooms to doubles,
    // then divide to get occupancy
    cout << "Occupancy: " << (static_cast<float>(totalOccupied) /
            static_cast<float>(totalRooms)) * 100 << "%" << endl;
}

void population()
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

void salesChart()
{
    // the number of stores
    const int NUM_STORES = 5;
    // a float for each store to store the sales
    float sales[NUM_STORES];
    
    // prompt user to input sales for each store
    cout << "Enter today's sales for store 1: ";
    cin >> sales[0];
    cout << "Enter today's sales for store 2: ";
    cin >> sales[1];
    cout << "Enter today's sales for store 3: ";
    cin >> sales[2];
    cout << "Enter today's sales for store 4: ";
    cin >> sales[3];
    cout << "Enter today's sales for store 5: ";
    cin >> sales[4];
    
    // display output
    cout << "SALES BAR CHART\n(Each * = $100)" << endl;
    
    // loop each store
    for (int i = 0; i < NUM_STORES; i++)
    {
        // add one star for each $100 in sales
        short stars = sales[i] / 100.0;
        
        switch (i)
        {
            case 0:
                cout << "Store 1: ";
                break;
            case 1:
                cout << "Store 2: ";
                break;
            case 2:
                cout << "Store 3: ";
                break;
            case 3:
                cout << "Store 4: ";
                break;
            case 4:
                cout << "Store 5: ";
                break;                    
        }
        
        // loop stars and output
        for (int j = 0; j < stars; j++) 
        {
            cout << "*";
        }
        cout << endl;
    }
}