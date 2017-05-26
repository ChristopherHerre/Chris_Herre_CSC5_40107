
/* 
 * File:   Knight.h
 * Author: chris
 *
 * Created on May 21, 2017, 12:24 PM
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>

#include "Piece.h"

using namespace std;

class Knight : public Piece
{
public:
    Knight();
    Knight(string position) : Piece(position)
    {
        this->symbol = "h";
    };
    virtual ~Knight();
    
    vector<string> getAvailPositions(Piece **all)
    {
        vector<string> v;
        stringstream ss;
        ss << static_cast<char>(position[0] + 2)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss.str());
        
        stringstream ss2;
        ss2 << static_cast<char>(position[0] + 2)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss2.str());
        
        stringstream ss3;
        ss3 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] + 2);
        v.push_back(ss3.str());
        
        stringstream ss4;
        ss4 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] + 2);
        v.push_back(ss4.str());
        
        stringstream ss5;
        ss5 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] - 2);
        v.push_back(ss5.str());
        
        stringstream ss6;
        ss6 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] - 2);
        v.push_back(ss6.str());
        
        stringstream ss7;
        ss7 << static_cast<char>(position[0] - 2)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss7.str());
        
        stringstream ss8;
        ss8 << static_cast<char>(position[0] - 2)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss8.str());
        return v;
    }
private:

};

#endif /* KNIGHT_H */

