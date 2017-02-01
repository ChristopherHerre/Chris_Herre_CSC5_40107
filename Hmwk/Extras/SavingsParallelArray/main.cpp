/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 31, 2017, 12:17 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void fillArray(int [], int);
float avgArray(int [], int);
void printArray(int [], float [], int);
void savings(int [], float [], float, float, float, int);

int main(int argc, char** argv) {
    cout << setprecision(2) << fixed;
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 200;
    int nYears = SIZE / 2 + 1;
    int year[SIZE] = {};
    float balance[SIZE] = {};
    
    float intRate = 0.06f;
    float gift = 2.0e4f;
    float salary = 1.2e5f;
    float percSav = 0.15f;
    
    float savReq = salary / intRate;
    float yDep = percSav * salary;
    savings(year, balance, gift, intRate, yDep, nYears);
    
    //fillArray(array, nYears);
    
    cout << "Our salary = $" << salary << endl;
    cout << "Yearly Savings Deposit = $" << yDep << endl;
    cout << "Savings goal = $" << savReq << endl;
    printArray(year, balance, nYears);
    
    return 0;
}

void printArray(int year[], float balance[], int n)
{
    cout << "Year Balance" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << year[i] << "\t$" << setw(11) << balance[i] << endl;
    }
    cout << endl;
}

void savings(int y[], float b[], float p, float intRate, float yDep, int nYears)
{
    y[0] = 0;
    b[0] = p;
    
    for (int year = 1; year < nYears; year++)
    {
        y[year] = year;
        b[year] = b[year - 1] * (1 + intRate);
        b[year] += yDep;
    }
}

float avgArray(int a[], int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum/n;
}