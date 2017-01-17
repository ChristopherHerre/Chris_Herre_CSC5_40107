/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 17, 2017, 12:12 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    unsigned char numStd = 20,
         student = 0;         //Number of students
    unsigned short average = 0;
    
    //Input values
    cout << "This program will take an input score and will output the letter grade for "
            << static_cast<int>(numStd) << " students." << endl;
    
    while(++student <= numStd)
    {
        unsigned short score = rand() % 50 + 50;
        average += score;

        char grade =(score>=90) ? 'A' :
                   (score>=80) ? 'B' :
                   (score>=70) ? 'C' :
                   (score>=60) ? 'D' :'F';
        
        cout << "Student " << setw(2) << static_cast<int>(student)
                << " has score " << score << " = " << grade << endl;
    }

    average /= numStd;
    cout << "The average test score is = " << average << endl;

    return 0;
}