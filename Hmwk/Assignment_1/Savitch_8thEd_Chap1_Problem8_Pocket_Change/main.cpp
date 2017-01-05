/* 
 * File:   main.cpp
 * Author: Christopher K. Herre
 * Created on January 5, 2017 1:40 PM
 * Purpose:  Pocket Change Assignment
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const char quarter = 25, // number of cents in coinage
            dime = 10,
            nickels = 5,
            penny = 1;
    char nQuarters, nDimes, nNickels, nPennies;
    unsigned short total;// total pocket change in cents.
    //Input or initialize values Here
    cout << "This calculates the amount of your pocket change." << endl;
    cout << "How many quarters, nickels, dimes, and pennies do" << endl;
    cout << "you have in your pocket?" << endl;
    cout << "Type all on the same line i.e. 3 4 0 2" << endl;
    cout << "Maximum of any value must be less than 10." << endl;
    cin >> nQuarters >> nDimes >> nNickels >> nPennies;
    total = (nQuarters - 48) * quarter +
            (nDimes - 48) * dime + 
            (nNickels - 48) * nickels +
            (nPennies - 48) * penny;
    //Process/Calculations Here
    
    //Output Located Here
    cout << "The coins in your pocket=" << total << " cents " << endl;
    cout << "The coins in your pocket=$" << total / 100.0f << " cents " << endl;

    //Exit
    return 0;
}

