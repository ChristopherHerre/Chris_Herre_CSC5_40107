
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 29, 2017, 12:56 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct SalesData
{
    string name;
    float firSales, secSales, thirSales, fourSales, avg;
    double total;
};

void getInput(SalesData);
void bubbleSort(float[], short);

int main(int argc, char** argv) {
    SalesData east = { "EAST" };
    SalesData west = { "WEST" };
    SalesData north = { "NORTH" };
    SalesData south = { "SOUTH" };
    
    getInput(east);
    getInput(west);
    getInput(north);
    getInput(south);
    return 0;
}

// collects the sales input for 4 quarters of a given division.
// will calculate a total and average of the input.
void getInput(SalesData div)
{
    cout << "Enter the first quarter sales for the " << div.name << " division: ";
    cin >> div.firSales;
    cout << div.firSales << endl;
    
    cout << "Enter the second quarter sales for the " << div.name << " division: ";
    cin >> div.secSales;
    cout << div.secSales << endl;
    
    cout << "Enter the third quarter sales for the " << div.name << " division: ";
    cin >> div.thirSales;
    cout << div.thirSales << endl;
    
    cout << "Enter the fourth quarter sales for the " << div.name << " division: ";
    cin >> div.fourSales;
    cout << div.fourSales << endl;
    
    div.total = div.firSales + div.secSales + div.thirSales + div.fourSales;
    cout << "TOTAL:\t" << div.total << endl;
    const short SIZE = 4;
    float data[SIZE] = { div.firSales, div.secSales, div.thirSales, div.fourSales };
    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << endl;
    }
    bubbleSort(data, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << data[i] << endl;
    }
    div.avg = div.total / SIZE;
    cout << "AVERAGE:\t" << div.avg << endl;
}

void bubbleSort(float data[], short size)
{
    cout << "starting bubble sort ..." << endl;
    bool swap;
    float temp;
    
    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (data[count] > data[count + 1])
            {
                temp = data[count];
                data[count] = data[count + 1];
                data[count + 1] = temp;
                swap = true;
            }
        }
    } while (temp);
    
}