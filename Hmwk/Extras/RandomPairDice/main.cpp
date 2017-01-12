/* 
 * File:   main.cpp
 * Author: Chris Herre
 * Created on January 9, 2017 11:30 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream> // i/o
#include <cstdlib> // random number generator and seed
#include <ctime> // time used for random seed

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    unsigned char die1, die2, sum;
    
    //Input or initialize values Here
    
    die1 = rand()% 6 + 1; // [1,6]
    die2 = rand()% 6 + 1; // [1,6]
    //Process/Calculations Here
    sum = die1 + die2;
    //Output Located Here
    cout << "Die 1\t= " << static_cast<int>(die1) << endl;
    cout << "Die 2\t= " << static_cast<int>(die2) << endl;
    cout << "Sum\t= " << static_cast<int>(sum) << endl;

    //Exit
    return 0;
}

