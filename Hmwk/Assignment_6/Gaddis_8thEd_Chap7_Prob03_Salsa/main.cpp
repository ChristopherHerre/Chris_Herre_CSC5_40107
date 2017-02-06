
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 6, 2017, 12:38 PM
 * 
 * 3. Chips and Salsa
 * Write a program that lets a maker of chips and salsa keep track of sales for
 * five different types of salsa: mild, medium, sweet, hot, and zesty. The
 * program should use two parallel 5-element arrays: an array of strings that
 * holds the five salsa names and an array of integers that holds the number of 
 * jars sold during the past month for each salsa type. The salsa names should
 * be stored using an initialization list at the time the name array is created.
 * The program should prompt the user to enter the number of jars sold for each
 * type. Once this sales data has been entered, the program should produce a
 * report that displays sales for each salsa type, total sales, and the names of
 * the highest selling and lowest selling products.
 * 
 * Input Validation: Do not accept negative values for number of jars sold.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    const short NUM_SALSAS = 5;
    string salsas[] = { "mild", "medium", "sweet", "hot", "zesty" };
    int sales[NUM_SALSAS] = {};
    
    for (int i = 0; i < NUM_SALSAS; i++)
    {
        cout << "Enter the sales for the " << salsas[i] << " salsa: ";
        cin >> sales[i];
        
        while (sales[i] < 1)
        {
            cout << "Sales cannot be less than 1!" << endl;
            cout << "Enter the sales for the " << salsas[i] << " salsa: ";
            cin >> sales[i];
        }
    }
    
    int temp;
    bool swap;
    
    // bubble sort the array
    // array may potentially already be sorted
    do
    {
        swap = false;
        for (short j = 0; j < NUM_SALSAS - 1; j++)
        {
            if (sales[j] > sales[j + 1])
            {
                temp = sales[j + 1];
                sales[j + 1] = sales[j];
                sales[j] = temp;
                swap = true;
            }
        }
    } while (swap);
    
    int totalSales = 0;
    bool extraTab = false;
    
    for (int j = 0; j < NUM_SALSAS; j++)
    {
        if (j == 0 || j == NUM_SALSAS - 1)
        {
            cout << (j == 0 ? "Lowest: " : "Highest: ");
            extraTab = true;
        }
        cout << salsas[j] << "\t\t" << (!extraTab ? "\t" : "") << sales[j] << endl;
        totalSales += sales[j];
        extraTab = false;
    }
    
    cout << "Total sales:\t\t" << totalSales << endl;
    return 0;
}

