
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 7, 2017, 10:31 PM
 * 
 * 13. Circuit Board Price
 * An electronics company sells circuit boards at a 35 percent profit. Write
 * a program that will calculate the selling price of a circuit board that
 * costs $14.95. Display the result on the screen.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // The cost to make the circuit board
    float cost = 14.95f;
    // the percent profit margin on the sale
    float margin = 0.35f;
    // the additional cost to the consumer besides the cost to make the board
    float markup = cost * margin;
    cout << "Selling price=$" << cost + markup << endl;
    return 0;
}

