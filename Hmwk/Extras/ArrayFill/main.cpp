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

using namespace std;

void fillArray(int [], int);
float avgArray(int [], int);
void printArray(int [], int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 200;
    int utilize = SIZE / 2;
    int array[SIZE] = {};
    
    fillArray(array, utilize);
    
    float avg = avgArray(array, SIZE);
    
    cout << "The entire array " << endl;
    printArray(array, SIZE);
    cout << "This average should be close to " << (99-10)/2.0f << endl;
    cout << "The actual average is " << avg << endl;
    
    
    return 0;
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (a[i] <= 9 ? ' ' : '\0') << a[i] << " ";
        
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
    cout << endl;
}

void fillArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 90 + 10;
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