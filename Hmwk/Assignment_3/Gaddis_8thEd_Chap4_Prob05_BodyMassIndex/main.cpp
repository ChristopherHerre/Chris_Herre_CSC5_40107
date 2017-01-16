
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 15, 2017, 12:16 PM
 * 
 * 5. Body Mass Index
 * Write a program that calculates and displays a person’s body mass index
 * (BMI). The BMI is often used to determine whether a person with a sedentary
 * lifestyle is over-weight or underweight for his or her height. A person’s
 * BMI is calculated with the following formula:
 * 
 * BMI  weight * 703 / height^2
 * 
 * where weight is measured in pounds and height is measured in inches. The
 * program should display a message indicating whether the person has optimal
 * weight, is under-weight, or is overweight. A sedentary person’s weight is 
 * considered to be optimal if his or her BMI is between 18.5 and 25. If the
 * BMI is less than 18.5, the person is considered to be underweight. If the
 * BMI value is greater than 25, the person is considered to be overweight.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    float weight, height, bmi;
    
    // prompt user to input values
    cout << "Enter the person's weight in pounds: ";
    cin >> weight;
    
    cout << "Enter the person's height in inches: ";
    cin >> height;
    
    // calc bmi
    bmi = weight * 700 / (height * height);
    
    cout << "BMI=" << bmi << endl;
    
    // check if person is underweight
    if (bmi < 18.5)
    {
        cout << "This person is underweight." << endl;
    }
    
    // check if person is in the optimal weight range
    if (bmi >= 18.5 && bmi < 25)
    {
        cout << "This person has optimal weight for their given height."
                << endl;
    }
    
    // check if the person is overweight
    if (bmi > 25)
    {
        cout << "This person is overweight." << endl;
    }
    return 0;
}

