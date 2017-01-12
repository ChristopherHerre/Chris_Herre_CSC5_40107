/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 10, 2017, 1:05 PM
 * 
 * 17. Math Tutor
 * Write a program that can be used as a math tutor for a young student. The
 * program should display two random numbers to be added, such as
 * 
 *   247
 * + 129
 * -----
 * 
 * The program should then pause while the student works on the problem. When
 * the student is ready to check the answer, he or she can press a key and the
 * program will display the correct solution:
 * 
 *   247
 * + 129
 * -----
 *   376 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    short x, y, answer;
    // min random value
    const short MIN_VALUE = 100;
    // max random value
    const short MAX_VALUE = 500;
    
    cout << "Welcome to Math Tutor - Created by Chris Herre.\n\n"
        "Enter your answer to the problem below:" << endl;
    
    begin:
    
    // this prevents getting the same random numbers each time
    srand(time(0));
    
    // set number x to a random number between 100-500
    x = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    // set number y to a random number between 100-500
    y = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    // output our problem
    cout << "  " << x << endl;
    cout << "+ " << y << endl;
    cout << "-----" << endl;
    cout << "= ";
    // ask the user for an answer
    cin >> answer;
    
    // is this the correct answer?
    if (answer == x + y)
    {
        // if so, tell the user they are smart
        cout << "  " << answer << " is correct!" << endl;
        cout << "Congratz! You understand basic math!" << endl;
    }
    // if not, display an oops message
    else
    {
        cout << "Answer: " << x + y << endl;
        cout << "Oops, looks like you need to go back to 1st grade :'(" << endl;
    }
    cout << "Lets try another problem:\n" << endl;
    // go to the "begin:" label up above and execute the program again
    // from there to keep the problems coming
    goto begin;
    return 0;
}