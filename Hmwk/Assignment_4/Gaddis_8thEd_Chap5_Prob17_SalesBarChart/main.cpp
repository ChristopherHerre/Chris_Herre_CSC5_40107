
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 19, 2017, 1:41 PM
 * 
 * 17. Sales Bar Chart
 * Write a program that asks the user to enter today’s sales for five stores.
 * The program should then display a bar graph comparing each store’s sales.
 * Create each bar in the bar graph by displaying a row of asterisks. Each
 * asterisk should represent $100 of sales.
 * 
 * Here is an example of the program’s output.
 * Enter today's sales for store 1: 1000 [Enter]
 * Enter today's sales for store 2: 1200 [Enter]
 * Enter today's sales for store 3: 1800 [Enter]
 * Enter today's sales for store 4: 800 [Enter]
 * Enter today's sales for store 5: 1900 [Enter]
 * SALES BAR CHART
 * (Each * = $100)
 * Store 1: **********
 * Store 2: ************
 * Store 3: ******************
 * Store 4: ********
 * Store 5: ******************* 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
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
    return 0;
}
