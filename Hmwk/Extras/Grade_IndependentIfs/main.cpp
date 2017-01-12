
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 12, 2017, 11:24 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    unsigned short score;
    char grade;
    
    cout << "This program takes the score and outputs the grade." << endl;
    cout << "Input the score 0 to 100" << endl;
    cin >> score;
    
    switch (score/10)
    {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }
    
    cout << grade << endl;
    return 0;
}

