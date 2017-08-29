
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
    
    vector<string> getAvailPositions(Piece **all, bool exclude)
    {
        vector<string> v;
        stringstream ss;
        ss << static_cast<char>(position[0])
                << static_cast<char>(position[1] + 1);
        v.push_back(ss.str());
        stringstream ss2;
        ss2 << static_cast<char>(position[0])
                << static_cast<char>(position[1] - 1);
        v.push_back(ss2.str());
        stringstream ss3;
        ss3 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss3.str());
        stringstream ss4;
        ss4 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss4.str());
        stringstream ss5;
        ss5 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss5.str());
        stringstream ss6;
        ss6 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss6.str());
        stringstream ss7;
        ss7 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1]);
        v.push_back(ss7.str());
        stringstream ss8;
        ss8 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1]);
        v.push_back(ss8.str());
        removeInvalids(v);
        rmvSameSymb(all, v);
        rmvSameSymb(all, v);
        return v;
    }
private:

};

#endif /* KING_H */

