/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
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
    // variable to build the big C with
    char c; 
    
    //Input or initialize values Here
    cout << "This program outputs a large C" << endl;
    cout << "With a letter the user chooses" << endl;
    cout << "What letter would you like? ";
    cin >> c;
    //Process/Calculations Here
    
    //Output Located Here
    
    cout << "  " << c << " " << c << " " << c << endl;
    cout << " " << c << "     " << c << endl;
    cout << c << endl;
    cout << c << endl;
    cout << c << endl;
    cout << c << endl;
    cout << c << endl;
    cout << " " << c << "     " << c << endl;
    
    cout << "  " << c << " " << c << " " << c << endl;
    //Exit
    return 0;
}

