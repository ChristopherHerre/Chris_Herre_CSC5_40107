
/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 17, 2017, 12:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void doWhileLoop();
void whileLoop();
void forLoop();

void doWhileLoop()
{
    srand(static_cast<unsigned int>(time(0)));
    
    char numStd = 20,
         student = 1;
    unsigned short average = 0;
    
    cout << "This program will take an input score and will output the letter grade for "
            << static_cast<int>(numStd) << " students." << endl;
    
    do
    {
        unsigned short score = rand() % 50 + 50;
        average += score;

        char grade =(score>=90) ? 'A' :
                   (score>=80) ? 'B' :
                   (score>=70) ? 'C' :
                   (score>=60) ? 'D' :'F';

        cout << "Student " << setw(2) << static_cast<int>(student)
                << " has score " << score << " = " << grade << endl;
    } while(++student <= numStd);
    
    average /= numStd;
    cout << "The average test score is = " << average << endl;
}

void forLoop()
{
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and Initialize local Variables to main
    char numStd = 20;
    unsigned short average = 0;
    
    //Input values
    cout << "This program will take an input score and will output the letter grade for "
            << static_cast<int>(numStd) << " students." << endl;
    
    //Loop for each student
    for(char student = 1; student <= numStd; student++)
    {
        unsigned short score = rand() % 50 + 50;
        average += score;
        //Process by mapping inputs to outputs
        char grade =(score>=90) ? 'A':
                   (score>=80) ? 'B' :
                   (score>=70) ? 'C' :
                   (score>=60) ? 'D' : 'F';
        cout << "Student " << setw(2) << static_cast<int>(student)
                << " has score " << score << " = " << grade << endl;
    }
    
    average /= numStd;
    cout << "The average test score is = " << average << endl;
}

void whileLoop()
{
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

        char grade =(score>=90)?'A':
                   (score>=80)?'B':
                   (score>=70)?'C':
                   (score>=60)?'D':'F';

        cout << "Student " << setw(2) << static_cast<int>(student)
                << " has score " << score << " = " << grade<<endl;
    }

    average /= numStd;
    cout << "The average test score is = " << average << endl;
}

int main(int argc, char** argv)
{
    char choice;
    
    // loop on the menu
    
    // input values
    
    do
    {
        cout << "Choose from the list" << endl;
        cout << "Type 1 for Problem with Do-While" << endl;
        cout << "Type 2 for Problem with While" << endl;
        cout << "Type 3 for Problem with For" << endl;
        cin >> choice;
        
        switch (choice)
        {
            case '1':
                doWhileLoop();
                break;
            case '2':
                whileLoop();
                cout << endl;
                break;
            case '3':
                forLoop();
                break;
            default:
                break;
        }
    } while (choice >= '1' && choice <= '3');
    return 0;
}

