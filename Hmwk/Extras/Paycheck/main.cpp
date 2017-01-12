
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 11, 2017, 12:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    float hours, rate, paycheck, otHours, otPay;
    
    cout << setprecision(2) << fixed;
    cout << "How many hours did you work this week?: ";
    cin >> hours;
    
    cout << "What is the rate of pay?: ";
    cin >> rate;
    cout << endl;
    
    // if hours is greater than 40
    if (hours > 40) {
        // get the otHours by subtracting 40 from hours
        otHours = hours - 40;
        // calculate otPay based on double the normal pay rate
        otPay = otHours * (rate * 2);
        // set hours back to 40 so the employee is only paid the standard rate
        // for these 40 hours
        hours -= otHours;
    }
    
    paycheck = hours * rate;
    cout << "You worked " << otHours << " hours of overtime." << endl;
    cout << "Your overtime pay is $" << otPay << "." << endl;
    cout << "Your pay check is $" << paycheck + otPay << "." << endl;
    return 0;
}
