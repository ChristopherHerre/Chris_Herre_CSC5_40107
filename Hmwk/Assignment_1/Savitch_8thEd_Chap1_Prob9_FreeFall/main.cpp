/* 
 * File:   main.cpp
 * Author: Christopher Herre
 * Created on January 5, 2017 1:09 AM
 * Purpose:  Free Fall
 */

//System Libraries Here
#include <iostream>
#include <cmath>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

// Gravity on the earth sea level ft/sec
const float GRAVITY = 3.2174e1f;

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    
    float time,// time in seconds
            dist; // distance in feet
    //Input or initialize values Here
    cout << "This problem solves the distance traveled" << endl;
    cout << "in free-fall under earth's gravity." << endl;
    cout << "Input the time during free-fall in seconds." << endl;
    cin >> time;
    //Process/Calculations Here
    dist = GRAVITY * time * time / 2;
    //Output Located Here
    cout << "The distance fallen = " << dist << " ft." << endl;

    //Exit
    return 0;
}

