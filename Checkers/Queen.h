/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queen.h
 * Author: chris
 *
 * Created on May 21, 2017, 2:46 PM
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <string>

#include "Piece.h"

using namespace std;

class Queen : public Piece
{
public:
    Queen();
    Queen(string position) : Piece(position)
    {
        this->symbol = "q";
    };
    virtual ~Queen();
    
    vector<string> getAvailPositions()
    {
        vector<string> v;
        return v;
    }
private:

};

#endif /* QUEEN_H */

