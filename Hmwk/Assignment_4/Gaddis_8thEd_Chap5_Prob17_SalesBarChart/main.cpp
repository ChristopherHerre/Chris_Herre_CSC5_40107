
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
    const int MAX_DIVS = 5;
    float sales[MAX_DIVS];
    
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
    

    for( int i = 0; i < MAX_DIVS ; i++){
        short stars = sales[i]/ 100.0;
        for (int s = 0; s< stars ; s++) 
        {
            cout << "*";
        }
        cout<<endl;
    }
    
    return 0;
}

