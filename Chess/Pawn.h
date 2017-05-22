
/* 
 * File:   Pawn.h
 * Author: chris
 *
 * Created on May 19, 2017, 9:26 PM
 */

#ifndef PAWN_H
#define PAWN_H

#include <string>

#include "Piece.h"

using namespace std;

class Pawn : public Piece
{
public:
    Pawn();
    Pawn(string position) : Piece(position)
    {
        this->symbol = "p";
    };
    virtual ~Pawn();

    void move(string newPos)
    {
        setPosition(newPos);
    }
    
    vector<string> getAvailPositions()
    {
        vector<string> v;
        return v;
    }
    //string getSymbol();
    //string move(string newPos);
    //vector<string> getAvailPositions();
private:

};

#endif /* PAWN_H */

