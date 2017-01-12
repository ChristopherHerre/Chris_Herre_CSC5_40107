
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 10, 2017, 10:26 AM
 * 
 * 18. Interest Earned
 * Assuming there are no deposits other than the original investment, the
 * balance in a savings account after one year may be calculated as
 * 
 * Amount = Principal * (1 + Rate / T )T
 * 
 * Principal is the balance in the savings account, Rate is the interest rate,
 * and T is the number of times the interest is compounded during a year
 * ( T is 4 if the interest is compounded quarterly). Write a program that asks
 * for the principal, the interest rate, and the number of times the interest
 * is compounded. It should display a report similar to
 * 
 * Interest Rate:       4.25%
 * Times Compounded:    12
 * Principal:           $ 1000.00
 * Interest:            $ 43.34
 * Amount in Savings:   $ 1043.34 
 * 
 */

#include <cstdlib>
#include <iostream>
// include the pow function 
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    float principal, interest, interestRate;
    short timesComp;
    float balance;
    
    // prompt the user to input a principal,
    // interestRate, and timesCompounded
    cout << "What is the principal?:" << endl;
    cin >> principal;
    
    cout << "What is the interest rate (format example: 4.25)?:" << endl;
    cin >> interestRate;
    
    cout << "What is the number of times compounded?:" << endl;
    cin >> timesComp;
    
    // example: format 4.25 as 0.0425 for accurate results
    interestRate /= 100.00f;
    
    // follow formula: Amount = Principal * (1 + Rate / T )T
    balance = principal
            * pow((1.0 + (interestRate / timesComp)), timesComp);
    // assign value to interest
    interest = balance - principal;
    
    // clear the screen of user inputs
    system("clear");
    
    // display results
    cout << "Interest Rate:\t\t" << interestRate << "% OR ("
            << interestRate * 100 << "%)" << endl;
    cout << "Times compounded:\t" << timesComp << endl;
    cout << "Principal:\t\t$" << principal << endl;
    cout << "Interest:\t\t$" << interest << endl;
    cout << "Amount in Savings:\t$" << balance << endl;
    return 0;
}