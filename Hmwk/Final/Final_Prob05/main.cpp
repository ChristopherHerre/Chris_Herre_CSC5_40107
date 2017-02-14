
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 13, 2017, 1:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    // store the file data in a string s
    string s;
    vector<string> vec;
    // the input file
    ifstream file;
    file.open("input.dat");
    // the next read char
    char c;
    
    if (file.is_open())
    {
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 15; x++)
            {
                // read the next character of the file
                file >> c;
                s = s + c;
                cout << c;
                
            }
            
            s = s + "\n";
            // store the strings in the vector
            vec.push_back(s);
            cout << endl;
        }
    }
    // close the input file
    file.close();
    
    cout << endl;

    // i couldn't get the sorting working correctly.
    // this is what i had so far
    for (int i = 0; i < 10 - 1; i++)
    {
        if (vec[i][0] > vec[i + 1][0])
        {
            string temp = vec.at(i);
            cout << temp << endl;
            vec.at(i) = vec.at(i + 1);
            vec.at(i + 1) = temp;
        }
    }     
    return 0;
}