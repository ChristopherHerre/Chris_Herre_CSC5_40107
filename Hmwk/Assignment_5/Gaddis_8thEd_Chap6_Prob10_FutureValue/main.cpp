
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 31, 2017, 5:43 PM
 * 
 * 10. Future Value
 * Suppose you have a certain amount of money in a savings account that earns
 * compound monthly interest, and you want to calculate the amount that you
 * will have after a specific number of months. The formula, which is known as
 * the future value formula, is:
 * 
 * F = P * (1 + i)^t
 * 
 * The terms in the formula are as follows:
 * • F is the future value of the account after the specified time period.
 * • P is the present value of the account.
 * • i is the monthly interest rate .
 * • t is the number of months .
 * Write a program that prompts the user to enter the account’s present value,
 * monthly interest rate, and the number of months that the money will be left
 * in the account. The program should pass these values to a function named
 * futureValue that returns the future value of the account, after the
 * specified number of months. The program should display the account’s future
 * value.
 * 
 * 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float futureValue(float, float, short);

int main(int argc, char** argv) {
    float f, p, i;
    short t;
    
    cout << "Enter the accounts present value: ";
    cin >> p;
    
    cout << "Enter the monthly interest rate: ";
    cin >> i;
    
    cout << "Enter the number of months: ";
    cin >> t;
    
    f = futureValue(p, i, t);
    cout << "Future value: " << f << endl;
    return 0;
}

float futureValue(float p, float i, short t)
{
    return p * pow((1 + i), t);
}
