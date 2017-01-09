
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 7, 2017, 11:03 PM
 *
 * 9. Cyborg Data Type Sizes
 * You have been given a job as a programmer on a Cyborg supercomputer. In
 * order to accomplish some calculations, you need to know how many bytes the
 * following data types use: char , int , float , and double . You do not have
 * any manuals, so you can’t look this information up. Write a C++ program
 * that will determine the amount of memory used by these types and display
 * the information on the screen.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char c;
    int i;
    float f;
    double d;
    
    // output the size in bytes of each datatype variable.
    cout << "Char memory used: " << sizeof(c) << " bytes\n"
            "Int memory used: " << sizeof(i) << " bytes\n"
            "Float memory used: " << sizeof(f) << " bytes\n"
            "Double memory used: " << sizeof(d) << " bytes\n" << endl;
    
    return 0;
}

