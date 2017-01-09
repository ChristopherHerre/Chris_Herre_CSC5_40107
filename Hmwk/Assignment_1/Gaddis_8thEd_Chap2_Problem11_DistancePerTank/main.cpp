
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 7, 2017, 10:49 PM
 * 
 * 11. Distance per Tank of Gas
 * A car with a 20-gallon gas tank averages 23.5 miles per gallon
 * when driven in town and 28.9 miles per gallon when driven on
 * the highway. Write a program that calculates and displays the
 * distance the car can travel on one tank of gas when driven in
 * town and when driven on the highway.
 * Hint: The following formula can be used to calculate the distance:
 * Distance  Number of Gallons  Average Miles per Gallon
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // the gas tanks fuel capacity in gallons
    unsigned char capacity = 20;
    // the miles per gallon in town
    float town = 23.5;
    // the miles per gallon on the highway
    float highway = 28.9;
    // the average distance that can be driven
    // on one tank of gas in town
    float townDist = capacity * town;
    // the average distance that can be driven
    // on one tank of gas on the highway
    float highwayDist = capacity * highway;
    cout << "We can drive " << townDist
            << " miles in town, or "
            << highwayDist << " on the highway." << endl;
    return 0;
}

