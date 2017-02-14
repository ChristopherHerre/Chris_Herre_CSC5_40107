
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 13, 2017, 6:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void fillVec(vector<short>&, int, bool);
void prntVec(vector<short>, vector<short>);

int main(int argc, char** argv) {
    vector<short> even;
    vector<short> odd;
    // the vector size input from the user
    int size;
    
    // set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    // prompt the user to input size value
    cout << "Enter the size of the even and odds vectors: ";
    cin >> size;
    
    // fill a vector with random even numbers
    fillVec(even, size, true);
    // fill a vector with random odd numbers
    fillVec(odd, size, false);
    
    //display the table of even and odd vectors
    cout << "Even\tOdd" << endl;
    prntVec(even, odd);
    return 0;
}

// prints a table of even and odd vectors
void prntVec(vector<short> even, vector<short> odd)
{
    for (int i = 0; i < even.size(); i++)
    {
        cout << even[i] << "\t" << odd[i] << endl;
    }
}

// populates a vector with random values
// if even is true, the values will only be even values
// if even is false, only odd values
void fillVec(vector<short>& vec, int size, bool even)
{
    for (int i = 0; i < size; i++)
    {
        short num = rand() % 99;
        if (even && num % 2 != 0)
        {
            num += 1;
        }
        else if (!even && num % 2 == 0)
        {
            num -= 1;
        }
        vec.push_back(num);
    }
}

