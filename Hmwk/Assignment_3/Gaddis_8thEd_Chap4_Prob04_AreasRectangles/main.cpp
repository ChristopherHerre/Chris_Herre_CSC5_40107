

/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 14, 2017, 10:04 PM
 * 
 * 4. Areas of Rectangles
 * The area of a rectangle is the rectangle’s length times its width. Write a
 * program that asks for the length and width of two rectangles. The program
 * should tell the user which rectangle has the greater area, or if the areas
 * are the same.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int getArea()
{
    float length, width;
    
    // prompt user for width and length
    cout << "\tEnter the length of the rectangle: ";
    cin >> length;
    
    cout << "\tEnter the width of the rectangle: ";
    cin >> width;
    
    cout << "Area: " << length * width << endl;
    return length * width;
}

int main(int argc, char** argv) {
    cout << "Enter the dimensions of rectangle 1." << endl;
    
    // assign area1 the return value of getArea() function
    int area1 = getArea();
    
    cout << "Enter the dimensions of rectangle 2." << endl;
    
    // assign area2 the return value of getArea() function
    int area2 = getArea();
    
    // if the areas are equal
    if (area1 == area2)
    {
        cout << "Both rectangles have the same area." << endl;
        return 0;
    }
   
    if (area1 < area2)
    {
        cout << "Rectangle 1 is smaller than rectangle 2." << endl;
    }
    else
    {
        cout << "Rectangle 2 is smaller than rectangle 1." << endl;
    }
    return 0;
}

