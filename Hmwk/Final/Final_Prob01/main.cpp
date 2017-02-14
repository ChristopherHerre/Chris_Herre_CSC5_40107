/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Chris
 *
 * Created on February 13, 2017, 8:44 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned short a = 106;
    
    while (a % 10 != 0)
    {
        cout << " ! " << endl;
        a -= 10;
    }
    return 0;
}

