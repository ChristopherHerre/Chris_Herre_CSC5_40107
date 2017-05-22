/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bishop.h
 * Author: chris
 *
 * Created on May 21, 2017, 1:15 PM
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <string>

#include "Piece.h"

using namespace std;

class Bishop : public Piece
{
public:
    Bishop();
    Bishop(string position) : Piece(position)
    {
        this->symbol = "b";
    };
    virtual ~Bishop();
    
    vector<string> getAvailPositions()
    {
        vector<string> v;
        return v;
    }
private:

};

#endif /* BISHOP_H */

