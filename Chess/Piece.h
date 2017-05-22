
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
    virtual void move(string newPos) = 0;
    virtual vector<string> getAvailPositions() = 0;
protected:
    string symbol;
    string position;
    vector<string> availPositions;
};

#endif /* PIECE_H */

