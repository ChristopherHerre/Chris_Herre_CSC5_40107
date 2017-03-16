
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 16, 2017, 1:04 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void printMean(short[], short);
void printArray(short [], short);
void bubbleSort(short [], short);
void printMedian(short [], const short);

int main(int argc, char** argv)
{
    short a[] = { 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5 };
    // for accurate answers, we must first sort the array
    bubbleSort(a, 13);
    // then find the mean, median, and mode
    printArray(a, 12);
    printMean(a, 12);
    printMedian(a, 12);
    return 0;
}

void printMode(short a[], short size)
{
    for (int i = 0 ; i < size; i++)
    {
        
    }
}

// find the median and print
void printMedian(short a[], const short size)
{
    short median = 0;

    if (size % 2 == 0)
    {
        // even
        // two medians
        short s = (size / 2) - 1;
        cout << "Median:\t" << a[s] << " " << a[s + 1] << endl; 
    }
    else
    {
        // odd
        // one median
        cout << "Median:\t" << a[size / 2] << endl;
        return;
    }
}

// find the mean and print
void printMean(short a[], const short size)
{
    // data set is sorted first
    int total = 0;
    short mean = 0;
    for (short i = 0; i < size; i++)
    {
        total += a[i];
    }
    mean = total / size;
    cout << "Mean:\t" << mean << endl;
}

// print the array contents
void printArray(short a[], short size)
{
    for (short i = 0; i < size; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

// sort the input array from least to greatest
void bubbleSort(short a[], short size)
{
    bool swap;
    short temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
                swap = true;
            }
        }
    } while (swap);
}