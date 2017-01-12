/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 10, 2017, 11:22 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // according to http://www.usgovernmentdebt.us/
    float usDebt = 19952808638850.59;
    // http://www.worldometers.info/world-population/us-population/
    int usPop = 325366700;
    
    // http://www.polidiotic.com/by-the-numbers/us-national-debt-by-year/
    float usDebt08 = 10024724896912.49;
    
    int usPop08 = 304000000;
    
    cout << "2008 U.S. debt per capita:\t$" << usDebt08 / usPop08 << endl;
    cout << "2016 U.S. debt per capita:\t$" << usDebt / usPop << endl;
    return 0;
}
