
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 16, 2017, 1:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void printMean(short[], short, bool);
void printArray(short [], short);
void bubbleSort(short [], short);
void printMedian(short [], const short);
void printMode(short [], short);
void mmm();
void prob02();
void arrSelectSort(int *[], int, bool);
void showArray(const int [], int);
void showArrPtr(int *[], int);
void prob06();
void prob07();
int doSomething(int*, int*);
int* dynAllocate(int);
void prob01();
void prob05();
void prob03();

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(0)));
    char c;
    
    do
    {
        cout << "1) Mean Median & Mode" << endl;
        cout << "2) Gaddis Chapter 9 Prob 02" << endl;
        cout << "3) Gaddis Chapter 9 Prob 06" << endl;
        cout << "4) Gaddis Chapter 9 Prob 07" << endl;
        cout << "5) Gaddis Chapter 9 Prob 05" << endl;
        cout << "6) Gaddis Chapter 9 Prob 01" << endl;
        cout << "7) Gaddis Chapter 9 Prob 03" << endl;
        
        cin >> c;
        switch (c - 48)
        {
            case 1:
                mmm();
                break;
            case 2:
                prob02();
                break;
            case 3:
                prob06();
                break;
            case 4:
                prob07();
                break;
            case 5:
                prob05();
                break;
            case 6:
                prob01();
                break;
            case 7:
                prob03();
                break;
        }
    } while (c - 48 > 0 && c - 48 < 9);
    
    return 0;
}

int* dynAllocate(int size)
{
    int* a = new int[size];
    for (int i = 0; i < size; i++)
    {
        *(a + i) = rand() % 100000;
        cout << *(a + i) << " ";
    }
    cout << endl;
    return a;
}

void prob01()
{
    int* a = dynAllocate(10);
    
}

void prob05()
{
    // add together 56 + 42, passing variables by address
    int x = 56, y = 42;
    cout << doSomething(&x, &y) << endl;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}


void prob06()
{
    int NUM_DONATIONS;
    
    cout << "How many donations? " << endl;
    cin >> NUM_DONATIONS;
    
    int* donations = new int[NUM_DONATIONS];
    
    for (int i = 0; i < NUM_DONATIONS; i++)
    {
        cout << "Input a donation value: ";
        cin >> *(donations + i);
    }
    
    for (int i = 0; i < NUM_DONATIONS; i++)
    {
        cout << *(donations + i) << endl;    
    }

    int *arrPtr[NUM_DONATIONS];
    
    for (int count = 0; count < NUM_DONATIONS; count++)
    {
        arrPtr[count] = &donations[count];
    }

    arrSelectSort(arrPtr, NUM_DONATIONS, true);
    
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
}

void prob07()
{
    int NUM_DONATIONS;
    
    cout << "How many donations? " << endl;
    cin >> NUM_DONATIONS;
    
    int* donations = new int[NUM_DONATIONS];
    
    for (int i = 0; i < NUM_DONATIONS; i++)
    {
        cout << "Input a donation value: ";
        cin >> *(donations + i);
    }
    
    for (int i = 0; i < NUM_DONATIONS; i++)
    {
        cout << *(donations + i) << endl;    
    }

    int *arrPtr[NUM_DONATIONS];
    
    for (int count = 0; count < NUM_DONATIONS; count++)
    {
        arrPtr[count] = &donations[count];
    }

    arrSelectSort(arrPtr, NUM_DONATIONS, false);
    
    cout << "The donations, sorted in decending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
}

void arrSelectSort(int *arr[], int size, bool asc)
{
    int startScan, minIndex;
    int *minElem;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (asc)
            {
                if (*(arr[index]) < *minElem)
                {
                    minElem = arr[index];
                    minIndex = index;
                }
            }
            else
            {
                if (*(arr[index]) > *minElem)
                {
                    minElem = arr[index];
                    minIndex = index;
                }
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void showArray(const int arr[], int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(arr + count) << " ";
    }
    cout << endl;
}

void showArrPtr(int *arr[], int size)
{
    for (int count = 0; count < size; count++)
    {
        cout << *(arr[count]) << " ";
    }
    cout << endl;
}


void prob02()
{
    short scores;
    cout << "How many test scores? ";
    cin >> scores;
    
    short* a = new short[scores];
    
    for (short i = 0; i < scores; i++)
    {
        cout << "Enter score #" << i + 1 << ": ";
        cin >> *(a + i);
        
        if (*(a + 1) < 0)
        {
            cout << "Input error! Bye!" << endl;
            exit(1);
        }
    }
    
    bubbleSort(a, scores);
    cout << "Sorting the input..." << endl;
    
    for (short i = 0; i < scores; i++)
    {
        cout << *(a + i) << endl;
    }
    
    // print the average
    printMean(a, scores, false);
}

// drop lowest test score
void prob03()
{
    short scores;
    cout << "How many test scores? ";
    cin >> scores;
    
    short* a = new short[scores];
    
    for (short i = 0; i < scores; i++)
    {
        cout << "Enter score #" << i + 1 << ": ";
        cin >> *(a + i);
        
        if (*(a + 1) < 0)
        {
            cout << "Input error! Bye!" << endl;
            exit(1);
        }
    }
    
    bubbleSort(a, scores);
    cout << "Sorting the input..." << endl;
    
    for (short i = 0; i < scores; i++)
    {
        cout << *(a + i) << endl;
    }
    
    cout << "Dropping the lowest test score before computing the average..."
            << endl;
    
    
    // print the average
    printMean(a, scores, true);
}


void mmm()
{
    const int SIZE = rand() % 5 + 5;
    short *a = new short[16];
    
    for (int i = 0; i < SIZE; i++)
    {
        *(a + i) = rand() % 9;
    }
    printArray(a, SIZE);
    // for accurate answers, we must first sort the array
    bubbleSort(a, SIZE);
    // then find the mean, median, and mode
    printArray(a, SIZE);
    printMean(a, SIZE, false);
    printMedian(a, SIZE);
    printMode(a, SIZE);
}

// need help finding the mode
void printMode(short a[], short size)
{
    cout << "-- Mode --" << endl;
    // container for the occurances of each value
    short occurances[99] = {};
    short mode = a[0];
    for (int i = 0 ; i < size; i++)
    {
        if (a[i] != mode)
        {
            mode = a[i];
        }
        occurances[mode]++;
    }
    
    cout << "Occurances array:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        cout << occurances[i] << "   ";
    }
    cout << endl;
    bubbleSort(occurances, size);
    cout << "Sorted Occurances array:" << endl;
    for (int i = 0 ; i < size; i++)
    {
        cout << occurances[i] << "   ";
    }
    cout << endl;
    
    cout << "Not finished :'(" << endl;
    
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
void printMean(short a[], const short size, bool drop)
{
    // data set is sorted first
    int total = 0;
    short mean = 0;
    for (short i = 0; i < size; i++)
    {
        total += a[i];
    }
    if (drop)
    {
        total -= a[0];
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