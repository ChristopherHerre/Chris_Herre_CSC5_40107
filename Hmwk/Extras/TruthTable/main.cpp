/* 
 * File:   main.cpp
 * Author: Chris Herre
 * Created on 1/11/17 10:49 AM
 * Purpose:  Truth table
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
    bool x, y;
    //Input or initialize values Here
    x = true;
    y = true;
    
    int index = 0;
    
    // create a point for the program to reloop
    restart:
    //Process/Calculations Here
    // display
    cout << "X Y !X !Y X&&Y X||Y X^Y X^Y^Y X^Y^X !(X&&Y) !X||!Y !(X||Y) !X&&!Y" << endl;
    cout << (x ? 'T' : 'F') << " ";
    cout << (y ? 'T' : 'F') << "  ";
    
    cout << (!x ? 'T' : 'F') << "  ";
    cout << (!y ? 'T' : 'F') << "   ";
    
    cout << (x&&y ? 'T' : 'F') << "    ";
    cout << (x||y ? 'T' : 'F') << "   ";
    cout << (x^y ? 'T' : 'F') << "    ";
    cout << (x^y^y ? 'T' : 'F') << "     ";
    cout << (x^y^x ? 'T' : 'F') << "       ";
    cout << (!(x&&y) ? 'T' : 'F') << "      ";
    cout << (!x||!y ? 'T' : 'F') << "       ";
    cout << (!(x||y) ? 'T' : 'F') << "      ";
    cout << (!x&&!y ? 'T' : 'F') << "      " << endl;
    
    y = false;
    index++;
    
    // if we've displayed twice, exit
    if (index > 1) {
        return 0;
    }
    
    // boom
    goto restart;
    //Exit
    return 0;
}