
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
    
    if (score >= 90) grade = 'A';
    if (score >= 80 && score < 90) grade = 'B';
    if (score >= 70 && score < 80 ) grade = 'C';
    if (score >= 60 && score < 70) grade = 'D';
    if (score >= 50  && score < 60) grade = 'F';
    
    cout << grade << endl;
    return 0;
}

