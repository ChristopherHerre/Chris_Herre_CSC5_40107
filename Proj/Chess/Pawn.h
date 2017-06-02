
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
        if (isupper(this->getSymbol()[0]))
        {
            if (this->getPosition()[0] == 'H')
                return v;
            // SW diag
            stringstream ss;
            ss << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1] - 1);
            if (isOcc(all, ss.str()))
                v.push_back(ss.str());
            // SE diag
            stringstream ss3;
            ss3 << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1] + 1);
            if (isOcc(all, ss3.str()))
                v.push_back(ss3.str());
            // straight South
            stringstream ss4;
            ss4 << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1]);
            if (!isOcc(all, ss4.str()))
            {
                v.push_back(ss4.str());
                // straight South x2
                stringstream ss7;
                ss7 << static_cast<char>(position[0] + 2)
                        << static_cast<char>(position[1]);
                // on pawns first move, it can move two spaces straight
                if (position[0] == 'B' && !isOcc(all, ss7.str()))
                {
                    v.push_back(ss7.str());
                }
            }     
        }
        else if (islower(this->getSymbol()[0]))
        {
            if (this->getPosition()[0] == 'A')
                return v;
            // NW diag
            stringstream ss1;
            ss1 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1] - 1);
            if (isOcc(all, ss1.str()))
                v.push_back(ss1.str());
            // NE diag
            stringstream ss2;
            ss2 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1] + 1);
            if (isOcc(all, ss2.str()))
                v.push_back(ss2.str());
            // straight North
            stringstream ss5;
            ss5 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1]);
            if (!isOcc(all, ss5.str()))
            {
                v.push_back(ss5.str());
                // straight North x2
                stringstream ss6;
                ss6 << static_cast<char>(position[0] - 2)
                        << static_cast<char>(position[1]);
                // on pawns first move, it can move two spaces straight
                if (position[0] == 'G' && !isOcc(all, ss6.str()))
                {
                    v.push_back(ss6.str());
                }
            }   
        }
        return v;
    }
private:
    //Queen queen;
};

#endif /* PAWN_H */

