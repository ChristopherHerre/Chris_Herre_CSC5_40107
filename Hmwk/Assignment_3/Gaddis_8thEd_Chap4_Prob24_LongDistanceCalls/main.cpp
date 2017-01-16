
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 12, 2017, 6:38 PM
 * 
 * 23. Geometry Calculator
 * Write a program that displays the following menu:
 * 
 * Geometry Calculator

 * 1. Calculate the Area of a Circle
 * 2. Calculate the Area of a Rectangle
 * 3. Calculate the Area of a Triangle
 * 4. Quit
 
 * Enter your choice (1-4):
 * If the user enters 1, the program should ask for the radius of the circle
 * and then display its area. Use the following formula:
 * 
 * area  π r 2
 * 
 * Use 3.14159 for π and the radius of the circle for r . If the user enters 2,
 * the program should ask for the length and width of the rectangle and then
 * display the rectangle’s area. Use the following formula:
 * 
 * area = length * width
 * 
 * If the user enters 3 the program should ask for the length of the triangle’s
 * base and its height, and then display its area. Use the following formula:
 * 
 * area = base * height * .5
 * 
 * If the user enters 4, the program should end.
 * Input Validation: Display an error message if the user enters a number
 * outside the range of 1 through 4 when selecting an item from the menu. Do
 * not accept negative values for the circle’s radius, the rectangle’s length
 * or width, or the triangle’s base or height.
 * 
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

using namespace std;

const float pi = 3.14159f;

void displayMenu()
{
    int menuChoice;
    // display the menu
    cout << "Geometry Calculator" << endl;
    cout << "\t1. Calculate the Area of a Circle" << endl;
    cout << "\t2. Calculate the Area of a Rectangle" << endl;
    cout << "\t3. Calculate the Area of a Triangle" << endl;
    cout << "\t4. Quit" << endl;
    cout << ">> ";
    
    cin >> menuChoice;
    
    // clear the screen
    system("clear");
    
    switch (menuChoice)
    {
        // menu option 1
        case 1:
            float radius;
        
            cout << "Enter the radius of the circle in centimeters: ";
            cin >> radius;
            
            if (radius < 1)
            {
                cout << "Radius cannot be negative!" << endl;
                break;
            }

            cout << "The area of a circle with a radius of " << radius
                    << "cm is " << (radius * radius) * pi << "cm squared."
                    << endl;
            break;
        // menu option 2
        case 2:
            float length, width;

            cout << "Enter the length of the rectangle in centimeters: ";
            cin >> length;
            
            if (length < 1)
            {
                cout << "Length cannot be negative!" << endl;
                break;
            }

            cout << "Enter the width of the rectangle in centimeters: ";
            cin >> width;
            
            if (width < 1)
            {
                cout << "Width cannot be negative!" << endl;
                break;
            }

            cout << "The area of the rectangle is " << length * width
                    << "cm squared." << endl;            
            break;
        // menu option 3
        case 3:
            float base, height;

            cout << "Enter the length of the triangles base in centimeters: ";
            cin >> base;
            
            if (base < 1)
            {
                cout << "Base cannot be negative!" << endl;
                break;
            }

            cout << "Enter the height of the triangle in centimeters: ";
            cin >> height;
            
            if (height < 1)
            {
                cout << "Height cannot be negative!" << endl;
                break;
            }

            cout << "The area of the triangle is " << base * height * 0.5
                    << "cm squared." << endl;        
            break;
        case 4:
            cout << "Goodbye!" << endl;
            return;
        default:
            cout << "Sorry, the only available options at the moment are 1-4."
                    << endl;
    }
    
    cout << endl;
    // recursively call displayMenu() function
    displayMenu();
}

int main(int argc, char** argv) {
    // call displayMenu function
    displayMenu();
    return 0;
}



