
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 19, 2017, 10:15 AM
 * 
 * 9. Hotel Occupancy
 * Write a program that calculates the occupancy rate for a hotel. The program
 * should start by asking the user how many floors the hotel has. A loop should
 * then iterate once for each floor. In each iteration, the loop should ask the
 * user for the number of rooms on the floor and how many of them are occupied.
 * After all the iterations, the program should display how many rooms the
 * hotel has, how many of them are occupied, how many are unoccupied, and the
 * percentage of rooms that are occupied. The percentage may be calculated by
 * dividing the number of rooms occupied by the number of rooms.
 * 
 * NOTE: It is traditional that most hotels do not have a thirteenth floor. The
 * loop in this program should skip the entire thirteenth iteration.
 * 294 Chapter 5 Loops and Files
 * Input Validation: Do not accept a value less than 1 for the number of floors.
 * Do not accept a number less than 10 for the number of rooms on a floor.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
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
        return 0;
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
    return 0;
}