
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 31, 2017, 1:15 PM
 * 
 * 6. Kinetic Energy
 * In physics, an object that is in motion is said to have kinetic energy. The
 * following formula can be used to determine a moving object’s kinetic energy:
 * 
 * KE  1/2 * mv^2
 * 
 * The variables in the formula are as follows: KE is the kinetic energy, m is
 * the object’s mass in kilograms, and v is the object’s velocity, in meters per
 * second.
 * 
 * Write a function named kineticEnergy that accepts an object’s mass (in kg)
 * and velocity (in meters per second) as arguments. The function should return
 * the amount of kinetic energy that the object has. Demonstrate the function
 * by calling it in a program that asks the user to enter values for mass and
 * velocity.
 * 
 */

#include <iostream>

using namespace std;

float kineticEnergy(float, float);

int main(int argc, char** argv) {
    float mass, vel;
    
    cout << "Enter the objects mass in kg: ";
    cin >> mass;
    
    cout << "Enter the objects velocity in m/s: ";
    cin >> vel;
    
    cout << "Kinetic Energy = " << kineticEnergy(mass, vel) << " Joules" << endl;
    return 0;
}

float kineticEnergy(float mass, float vel)
{
    return 0.5 * mass * (vel * vel);
}

