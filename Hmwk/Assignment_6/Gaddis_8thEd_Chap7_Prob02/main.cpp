
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 6, 2017, 10:32 AM
 * 
 * 2. Rainfall Statistics
 * Write a program that lets the user enter the total rainfall for each of 12
 * months into an array of doubles. The program should calculate and display
 * the total rainfall for the year, the average monthly rainfall, and the
 * months with the highest and lowest amounts.
 * 
 * Input Validation: Do not accept negative numbers for monthly rainfall figures
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const short MONTHS = 12;
    // an array to store 12 months of rainfall
    float rainfall[MONTHS];
    
    // loop 10 times
    for (short i = 0; i < MONTHS; i++)
    {
        // ask for 12 floats, store into rainfall array
        cout << "Enter the rainfall for month " << i + 1 << ": ";
        cin >> rainfall[i];
        
        // validate rainfall[i]
        while (rainfall[i] < 0.0)
        {
            cout << "Rainfall cannot be negative! Try again!" << endl;
            cout << "Enter the rainfall for month " << i + 1 << ": ";
            cin >> rainfall[i];
        }
    }
    
    char temp;
    bool swap;
    
    // bubble sort the array
    // array may potentially already be sorted
    do
    {
        swap = false;
        for (short j = 0; j < MONTHS - 1; j++)
        {
            if (rainfall[j] > rainfall[j + 1])
            {
                temp = rainfall[j + 1];
                rainfall[j + 1] = rainfall[j];
                rainfall[j] = temp;
                swap = true;
            }
        }
    } while (swap);
    
    float totalRain = 0.0f;
    // output the lowest and highest values in the array
    for (short k = 0; k < MONTHS; k++)
    {
        if (k == 0 || k == MONTHS - 1)
        {
            cout << (k == 0 ? "Lowest: " : "Highest: ");
        }
        cout << rainfall[k] << endl;
        totalRain += rainfall[k];
    }
    
    cout << "Total rainfall: " << totalRain << endl;
    cout << "Average monthly rainfall: " << totalRain / MONTHS << endl;
    return 0;
}