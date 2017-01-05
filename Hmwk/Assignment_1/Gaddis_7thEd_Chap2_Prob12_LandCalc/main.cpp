/* 
 * File:   main.cpp
 * Author: Christopher K. Herre
 * Created on January 4, 2017, 9:07 AM
 * Purpose:  Land Calc Problem
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
    int nAcres, nFt2;
    const int SQUARE_FT_IN_ACRE = 43560;
    
    //Input or initialize values Here
    
    cout << "This is a conversion program" << endl;
    cout << "from number of Acres to Feet squared" << endl;
    cout << "Input number of acres" << endl;
    cin >> nAcres;
    //Process/Calculations Here
    nFt2 = nAcres * SQUARE_FT_IN_ACRE;
    //Output Located Here
    
    cout << "The number of Acres input = " << nAcres << endl;
    cout << "Equivilant to " << nFt2 << endl;
    //Exit
    return 0;
}

