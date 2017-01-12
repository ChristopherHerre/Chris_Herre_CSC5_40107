/* 
 * File:   main.cpp
 * Author:  Chris Herre
 *
 * Created on January 9, 2017, 1:44 PM
 * 
 * 2. Stadium Seating
 * There are three seating categories at a stadium. For a softball game,
 * Class A seats cost $15, Class B seats cost $12, and Class C seats cost $9.
 * Write a program that asks how many tickets for each class of seats were
 * sold, then displays the amount of income generated from ticket sales.
 * Format your dollar amount in fixed-point notation, with two
 * decimal places of precision, and be sure the decimal point is always
 * displayed. 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // cost of class A seats in dollars
    unsigned char seatACost = 15;
    // cost of class B seats in dollars
    unsigned char seatBCost = 12;
    // cost of class C seats in dollars
    unsigned char seatCCost = 9;
    // storage variables for user input
    short numA, numB, numC;
    
    cout << "How many A class seats were sold? ";
    cin >> numA;
    cout << "How many B class seats were sold? ";
    cin >> numB;
    cout << "How many C class seats were sold? ";
    cin >> numC;
    cout << endl;
    cout << "Total revenue from tickets sold: $" << (seatACost * numA)
            + (seatBCost * numB)
            + (seatCCost * numC);
    return 0;
}