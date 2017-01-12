
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 9, 2017, 5:11 PM
 * 
 * 19. Monthly Payments
 * The monthly payment on a loan may be calculated by the following formula:
 * 
 * Payment =
 * Rate * (1 + Rate) N
 * * L
 * ((1 + Rate) N - 1)
 * 
 * Rate is the monthly interest rate, which is the annual interest rate divided
 * by 12. (12% annual interest would be 1 percent monthly interest.) N is the
 * number of payments, and L is the amount of the loan. Write a program that
 * asks for these values and displays a report similar to
 * 
 * Loan Amount:             $ 10000.00
 * Monthly Interest Rate:   1%
 * Number of Payments:      36
 * Monthly Payment:         $ 332.14
 * Amount Paid Back:        $ 11957.15
 * Interest Paid:           $ 1957.15
 * 
 */

#include <cstdlib>
#include <iostream>
// pow function import
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    // the amount of the loan
    float l = 10000;
    // the interest rate on the loan
    float interestRate = 0.01f;
    // the number of payments paid so far
    short n = 36;
    // formula for calculating the monthly loan payment
    float monthlyPayment;
    
    // (rate * (1 + rate)^n all over ((1 + rate)^n - 1) * L)
    monthlyPayment = ((interestRate * pow(1 + interestRate, n))
            / (pow(1 + interestRate, n) - 1) * l);
    
    // output our variables...
    cout << setprecision(2) << fixed;
    cout << "Loan Amount:\t\t$ " << l << endl;
    cout << "Monthly Interest Rate:\t" << "  " << interestRate << endl;
    cout << "Number of Payments:\t" << "  " << n << endl;
    cout << "Monthly Payment:\t$ " << monthlyPayment << endl;
    cout << "Amount Paid Back:\t$ " << monthlyPayment * n << endl;
    cout << "Interest Paid:\t\t$ " << monthlyPayment * n - l << endl;
    return 0;
}

