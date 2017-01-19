
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 19, 2017, 1:11 PM
 * 
 * 11. Population
 * Write a program that will predict the size of a population of organisms. The
 * program should ask the user for the starting number of organisms, their
 * average daily population increase (as a percentage), and the number of days
 * they will multiply. A loop should display the size of the population for
 * each day.
 * 
 * Input Validation: Do not accept a number less than 2 for the starting size
 * of the population. Do not accept a negative number for average daily
 * population increase. Do not accept a number less than 1 for the number of
 * days they will multiply.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
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
        return 0;
    }
    
    // prompt user to enter the population increase percentage
    cout << "What is the population increase percentage?: ";
    cin >> popIncrease;
    
    // check if percentage is less than or equal to 0
    if (popIncrease <= 0)
    {
        cout << "Population increase percentage must be a positive number!" << endl;
        return 0;
    }
    
    // prompt the user to enter number of days the organisms will multiply for
    cout << "How many days will the organisms multiply for? ";
    cin >> days;
    
    // days cannot be less than 1
    if (days < 1)
    {
        cout << "Days cannot be less than 1!" << endl;
        return 0;
    }
    
    // loop as many times as the value of days
    for (int i = 1; i <= days; i++)
    {
        // increase population size by the percentage of population increase
        nOrganisms += nOrganisms * popIncrease;
        cout << "Day " << i << ": Population is " << nOrganisms << endl;
    }
    return 0;
}

