
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

using namespace std;

int main(int argc, char** argv) {
    short floors, totalRooms = 0;
    
    cout << "How many floors does the hotel have? ";
    cin >> floors;
    
    if (floors < 1)
    {
        cout << "Floors cannot be less than 1!" << endl;
        return 0;
    }
    
    for (int i = 1; i <= floors; i++)
    {
        if (i == 13)
        {
            cout << ". . . Skipping the 13th floor . . . " << endl;
            continue;
        }
        
        float rooms, occupied;
        
        cout << "How many rooms are on floor " << i << "? ";
        cin >> rooms;
        totalRooms += rooms;
        
        if (rooms < 10)
        {
            cout << "There should be at least 10 rooms per floor!" << endl;
            break;
        }
        
        cout << "How many rooms are occupied on this floor? ";
        cin >> occupied;
        
        if (occupied > rooms)
        {
            cout << "Rooms occupied cannot be greater than the total number of"
                    " rooms on this floor." << endl;
            break;
        }
        
        float occupancy = occupied / rooms;
        cout << i << " " << occupied << "/" << rooms << " occupancy=" << occupancy << "%" << " unoccupancy= " << 1.0 - occupancy << "%" << endl;
    }
    cout << "Total rooms: " << totalRooms << endl;
    return 0;
}

