
/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 12, 2017, 12:11 PM
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
    
    switch (score >=95)
    {
        case true:
            grade = 'A';
            break;
        default:
            switch (score >= 87)
            {
                case true:
                    grade = 'B';
                    break;
                default:
                    switch (score >= 80)
                    {
                        case true:
                            grade = 'C';
                            break;
                        default: 
                            switch (score >= 75)
                            {
                                case true:
                                    grade = 'D';
                                    break;
                                default:
                                    grade = 'F';
                            }
                    }
            }
    }
    
    
    cout << grade << endl;
    return 0;
}

