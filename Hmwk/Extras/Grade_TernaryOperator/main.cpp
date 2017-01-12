
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
    
    grade = (score >= 90) ? 'A' :
        (score >= 80) ? 'B' :
            (score >= 70) ? 'C' :
                (score >= 60) ? 'D' : 'F';
    
    cout << grade << endl;
    return 0;
}

