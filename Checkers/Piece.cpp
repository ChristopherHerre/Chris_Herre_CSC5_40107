
/* 
 * File:   Piece.cpp
 * Author: chris
 * 
 * Created on May 19, 2017, 8:51 PM
 */

#include "Piece.h"

Piece::Piece()
{
    
}

Piece::Piece(string position)
{
    this->position = position;
}

Piece::~Piece()
{
    
}

string Piece::getSymbol()
{
    return symbol;
}

void Piece::setSymbol(char symbol)
{
    stringstream ss;
    ss << symbol;
    this->symbol = ss.str();
}

string Piece::getPosition()
{
    return position;
}

void Piece::setPosition(string position)
{
    this->position = position;
}

void Piece::move(Piece **all, fstream& f, map<string, int>& m,
        string input, string input2)
{
    bool occ = false;
    for (short i = 0; i < 32; i++)
    {
        if (all[i]->getPosition() == input2)
        {
            cout << input2 << " is occupied!" << endl;
            occ = true;
            break;
        }
    }
    if (!occ)
    {
        setPosition(input2);
        f.seekp(m[input2]);
        f.write(this->getSymbol().c_str(), 1);
        f.seekp(m[input]);
        f.write(" ", 1);
    }
    
}
