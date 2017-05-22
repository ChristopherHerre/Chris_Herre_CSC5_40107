
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
    
    vector<string> getAvailPositions()
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
        
        cout << v[0] << endl;
        cout << v[1] << endl;
        cout << v[2] << endl;
        cout << v[3] << endl;
        return v;
    }
    //string getSymbol();
    //string move(string newPos);
    //vector<string> getAvailPositions();
private:

};

#endif /* PAWN_H */

