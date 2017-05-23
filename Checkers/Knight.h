
/* 
 * File:   Knight.h
 * Author: chris
 *
 * Created on May 21, 2017, 12:24 PM
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

#include "Piece.h"

using namespace std;

class Knight : public Piece
{
public:
    Knight();
    Knight(string position) : Piece(position)
    {
        this->symbol = "h";
    };
    virtual ~Knight();
    
    vector<string> getAvailPositions(Piece **all)
    {
        vector<string> v;
        return v;
    }
private:

};

#endif /* KNIGHT_H */

