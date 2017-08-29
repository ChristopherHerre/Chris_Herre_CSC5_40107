
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
    static void drawPieces(fstream& file, map<string, int>& m,
        Piece **pieces, short iters);
    static Piece* getPieceForPos(Piece **all, string s);
    virtual vector<string> getAvailPositions(Piece **all, bool exclude) = 0;
    
protected:
    string symbol;
    string position;
    static char valids[16];
    void removeInvalids(vector<string>& v);
    void rmvSameSymb(Piece **piece, vector<string>& v);
    bool isOcc(Piece **all, string s);
    bool sameSymb(string s);
};

#endif /* PIECE_H */

