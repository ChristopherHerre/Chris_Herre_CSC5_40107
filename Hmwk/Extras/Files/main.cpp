/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on January 18, 2017, 10:18 AM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream inputFile;
    string var;
    inputFile.open("C:/Users/rcc/Desktop/hello.txt");
    inputFile >> var;
    cout << var << endl;
    inputFile.close();
    /*ofstream outputFile;
    outputFile.open("C:/Users/rcc/Desktop/hello.txt");
    
    
    outputFile << "Hello worldddddd";
    
    outputFile.close();*/
    return 0;
}

