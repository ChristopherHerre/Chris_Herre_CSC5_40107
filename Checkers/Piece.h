
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
#include <algorithm>

using namespace std;

class Piece
{
public:
    Piece(string position);
    virtual ~Piece();
    string getPosition();
    void setPosition(string position);
    string getSymbol();
    void setSymbol(char symbol);
    void move(Piece **all, fstream& f, map<string, int>& m,
        string input, string input2);
    bool isOcc(Piece **all, string s);
    static void drawPieces(fstream& file, map<string, int>& m, Piece **pieces,
        short iters);
    virtual vector<string> getAvailPositions(Piece **all) = 0;
    static char valids[16];
protected:
    string symbol;
    string position;
    vector<string> availPositions;
};

#endif /* PIECE_H */

