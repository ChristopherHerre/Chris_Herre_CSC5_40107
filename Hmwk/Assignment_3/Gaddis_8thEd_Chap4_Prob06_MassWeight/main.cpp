
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 16, 2017, 4:47 AM
 * 
 * 6. Mass and Weight
 * Scientists measure an object’s mass in kilograms and its weight in newtons.
 * If you know the amount of mass that an object has, you can calculate its
 * weight, in newtons, with the following formula:
 * 
 * Weight = mass * 9.8
 * 
 * Write a program that asks the user to enter an object’s mass, and then
 * calculates and displays its weight. If the object weighs more than 1,000
 * newtons, display a message indicating that it is too heavy. If the object
 * weighs less than 10 newtons, display a message indicating that the object is
 * too light.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    float mass, weight;
    
    // prompt user for mass input
    cout << "Enter an object's mass in kg: ";
    cin >> mass;
    
    // convert mass to Newtons
    weight = mass * 9.8;
    
    // check if object is too heavy
    if (weight > 1000)
    {
        cout << "This object is too heavy." << endl;
        return 0;
    }
    // check if object is too light
    else if (weight < 10)
    {
        cout << "This object is too light." << endl;
        return 0;
    }
    
    cout << mass << "kg = " << weight << " newtons." << endl;
    return 0;
}

