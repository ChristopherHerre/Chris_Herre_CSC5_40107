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
void savings(int [], float [], float, float, int);

int main(int argc, char** argv) {
    cout << setprecision(2) << fixed;
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 200;
    int nYears = SIZE / 2 + 1;
    int year[SIZE] = {};
    float balance[SIZE] = {};
    
    float intRate = 0.06f;
    float gift = 1.0e4f;
    
    savings(year, balance, gift, intRate, nYears);
    
    //fillArray(array, nYears);
    
    printArray(year, balance, nYears);
    
    return 0;
}

void printArray(int year[], float balance[], int n)
{
    cout << "Year Balance" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << year[i] << "\t$" << setw(10) << balance[i] << endl;
    }
    cout << endl;
}

void savings(int y[], float b[], float p, float intRate, int nYears)
{
    y[0] = 0;
    b[0] = p;
    
    for (int year = 1; year < nYears; year++)
    {
        y[year] = year;
        b[year] = b[year - 1] * (1 + intRate);
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