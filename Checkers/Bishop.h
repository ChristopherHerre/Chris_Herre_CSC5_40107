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
    
    vector<string> getAvailPositions(Piece **all)
    {
        vector<string> v;
        bool blocked1 = false;
        bool blocked2 = false;
        bool blocked3 = false;
        bool blocked4 = false;
        for (short i = 1; i < 8; i++)
        {
            stringstream ss;
            ss << static_cast<char>(position[0] + i)
                    << static_cast<char>(position[1] + i);
            if (!blocked1)
            {
                v.push_back(ss.str());
                if (isOcc(all, ss.str()))
                    blocked1 = true;
            }
            stringstream ss1;
            ss1 << static_cast<char>(position[0] - i)
                    << static_cast<char>(position[1] - i);
            if (!blocked2)
            {
                v.push_back(ss1.str());
                if (isOcc(all, ss1.str()))
                    blocked2 = true;
            }
            stringstream ss2;
            ss2 << static_cast<char>(position[0] + i)
                    << static_cast<char>(position[1] - i);
            if (!blocked3)
            {
                v.push_back(ss2.str());
                if (isOcc(all, ss2.str()))
                    blocked3 = true;
            }
            stringstream ss3;
            ss3 << static_cast<char>(position[0] - i)
                    << static_cast<char>(position[1] + i);
            if (!blocked4)
            {
                v.push_back(ss3.str());
                if (isOcc(all, ss3.str()))
                    blocked4 = true;
            }
        }
        removeInvalids(v);
        rmvSameSymb(all, v);
        rmvSameSymb(all, v);
        return v;
    }
private:

};

#endif /* BISHOP_H */

