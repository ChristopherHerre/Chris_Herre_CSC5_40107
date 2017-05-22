
/* 
 * File:   Piece.h
 * Author: chris
 *
 * Created on May 19, 2017, 8:51 PM
 */

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class Piece {
public:
    Piece();
    Piece(string position);
    virtual ~Piece();
    string getPosition();
    void setPosition(string position);
    string getSymbol();
    void setSymbol(char symbol);
    void move(Piece **all, fstream& f, map<string, int>& m,
        string input, string input2);
    virtual vector<string> getAvailPositions() = 0;
protected:
    string symbol = "J";
    string position;
    vector<string> availPositions;
};

#endif /* PIECE_H */
