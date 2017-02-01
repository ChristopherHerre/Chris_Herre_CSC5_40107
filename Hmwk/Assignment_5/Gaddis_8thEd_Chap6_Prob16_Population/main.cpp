
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 1, 2017, 12:10 PM
 * 
 * 16. Population
 * In a population, the birth rate is the percentage increase of the population
 * due to births, and the death rate is the percentage decrease of the
 * population due to deaths. Write a program that displays the size of a
 * population for any number of years. The program should ask for the following
 * data:
 * 
 * • The starting size of a population
 * • The annual birth rate
 * • The annual death rate
 * • The number of years to display
 * 
 * Write a function that calculates the size of the population for a year.
 * The formula is
 * 
 * N = P + BP − DP
 * 
 * where N is the new population size, P is the previous population size, B is
 * the birth rate, and D is the death rate.
 * 
 * Input Validation: Do not accept numbers less than 2 for the starting size.
 * Do not accept negative numbers for birth rate or death rate. Do not accept
 * numbers less than 1 for the number of years.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

float getPopSize(int, float, float);

int main(int argc, char** argv) {
    int p = 0;
    float birth = 0.0f, death = 0.0f;
    short years = 0;
    
    cout << "Enter the number of years: ";
    cin >> years;

    if (years < 1)
    {
        cout << "Years must be at least 1!" << endl;
        exit(0);        
    } 
    
    
    for (int i = 0; i < years; i++)
    {
    
        if (p == 0)
        {
            cout << "Enter the starting population size: ";
            cin >> p;

            if (p < 2)
            {
                cout << "Starting population size must be greater than 2!" << endl;
                exit(0);
            }
        }

        cout << "Enter the annual birth rate: ";
        cin >> birth;

        if (birth < 1.0)
        {
            cout << "Birth rate must be greater than 1.0!" << endl;
            exit(0);        
        }

        cout << "Enter the annual death rate: ";
        cin >> death;

        if (death < 1.0)
        {
            cout << "Death rate must be greater than 1.0!" << endl;
            exit(0);        
        }

        float size = getPopSize(p, birth, death);
        cout << "New population size: " << size << endl;
    }
    return 0;
}

float getPopSize(int p, float birthRate, float deathRate)
{
    return p + (birthRate * p) - (deathRate * p);
}

