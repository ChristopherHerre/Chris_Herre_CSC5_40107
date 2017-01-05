/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float PERCENT = 100;

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float stockPrice = 35.00f; // units of $'s per share
    unsigned short shares = 750; // number of shares
    const float commission = 2.0f; // commission percentage
    unsigned short stockPaid, comPaid, totalPaid;
    
    //Input or initialize values Here
    
    //Process/Calculations Here
    stockPaid = stockPrice * shares; // amount paid for the stock purchase
    comPaid = (stockPaid * commission) / PERCENT; // commission on stock purchase
    totalPaid = stockPaid + comPaid; // total paid $s
    
    //Output Located Here
    cout << "Stock price/share=\t$" << stockPrice << "/share" << endl;
    cout << "Number of shares=\t" << shares << endl;
    cout << "Commission=\t\t" << commission << "%" << endl;
    cout << "Stock price paid=\t$" << stockPrice * shares << endl;
    cout << "Commission paid=\t$" << comPaid << endl;
    cout << "Total paid=\t\t$" << totalPaid << endl;
    getchar();
    //Exit
    return 0;
}

