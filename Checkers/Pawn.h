
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
    vector<string> getAvailPositions(Piece **all)
    {
        vector<string> v;
        stringstream ss;
        ss << static_cast<char>(position[0] + 1) << position[1];
        v.push_back(ss.str());
        stringstream ss1;
        ss1 << static_cast<char>(position[0] - 1) << position[1];
        v.push_back(ss1.str());
        stringstream ss2;
        ss2 << static_cast<char>(position[0])
                << static_cast<char>(position[1] + 1);
        v.push_back(ss2.str());
        stringstream ss3;
        ss3 << static_cast<char>(position[0])
                << static_cast<char>(position[1] - 1);
        v.push_back(ss3.str());
        for (short i = 0; i < 32; i++)
        {
            if (all[i]->getPosition() == v[0])
            {
                swap(v[0], v.back());
                v.pop_back();
            }
            else if (all[i]->getPosition() == v[1])
            {
                swap(v[1], v.back());
                v.pop_back();
            }
            else if (all[i]->getPosition() == v[2])
            {
                swap(v[2], v.back());
                v.pop_back();
            }
            else if (all[i]->getPosition() == v[3])
            {
                swap(v[3], v.back());
                v.pop_back();
            }
        }
        return v;
    }
private:

};

#endif /* PAWN_H */

