
/* 
 * File:   King.h
 * Author: chris
 *
 * Created on May 21, 2017, 2:37 PM
 */

#ifndef KING_H
#define KING_H

#include <string>

#include "Piece.h"

using namespace std;

class King : public Piece
{
public:
    King();
    King(string position) : Piece(position)
    {
        this->symbol = "k";
    };
    virtual ~King();
    
    vector<string> getAvailPositions()
    {
        vector<string> v;
        return v;
    }
private:

};

#endif /* KING_H */

