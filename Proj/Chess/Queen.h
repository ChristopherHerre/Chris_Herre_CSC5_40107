
/* 
 * File:   Queen.h
 * Author: chris
 *
 * Created on May 21, 2017, 2:46 PM
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <string>

#include "Bishop.h"
#include "Rook.h"
#include "Piece.h"

using namespace std;

/**
 * Inherits the Bishop's movements, as well as the Rook's movements.
 */
class Queen : public Bishop
{
public:
    Queen();
    Queen(string position) : Bishop(position)
    {
        this->symbol = "q";
    };
    virtual ~Queen();
    
    vector<string> getAvailPositions(Piece **all, bool exclude)
    {
        vector<string> v = Bishop::getAvailPositions(all, exclude);
        // Rook movements
        bool blocked1 = false;
        bool blocked2 = false;
        bool blocked3 = false;
        bool blocked4 = false;
        for (short i = 1; i < 8; i++)
        {
            stringstream ss;
            ss << static_cast<char>(position[0])
                    << static_cast<char>(position[1] + i);
            if (!blocked1)
            {
                v.push_back(ss.str());
                if (isOcc(all, ss.str()))
                    blocked1 = true;
            }
            stringstream ss1;
            ss1 << static_cast<char>(position[0])
                    << static_cast<char>(position[1] - i);
            if (!blocked2)
            {
                v.push_back(ss1.str());
                if (isOcc(all, ss1.str()))
                    blocked2 = true;
            }
            stringstream ss2;
            ss2 << static_cast<char>(position[0] + i)
                    << static_cast<char>(position[1]);
            if (!blocked3)
            {
                v.push_back(ss2.str());
                if (isOcc(all, ss2.str()))
                    blocked3 = true;
            }
            stringstream ss3;
            ss3 << static_cast<char>(position[0] - i)
                    << static_cast<char>(position[1]);
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

#endif /* QUEEN_H */

