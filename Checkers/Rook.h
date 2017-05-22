/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rook.h
 * Author: chris
 *
 * Created on May 21, 2017, 1:45 PM
 */

#ifndef ROOK_H
#define ROOK_H

#include <string>

#include "Piece.h"

using namespace std;

class Rook : public Piece
{
public:
    Rook();
    Rook(string position) : Piece(position)
    {
        this->symbol = "r";
    };
    virtual ~Rook();
    
    vector<string> getAvailPositions()
    {
        vector<string> v;
        return v;
    }
private:

};

#endif /* ROOK_H */

