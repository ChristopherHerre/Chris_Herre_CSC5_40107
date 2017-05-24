
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
    if (!occ)
    {
        setPosition(input2);
        f.seekp(m[input2]);
        f.write(this->getSymbol().c_str(), 1);
        f.seekp(m[input]);
        f.write(" ", 1);
        // capture
        /*for (short i = 0; i < 32; i++)
        {
            if (all[i]->getPosition() == input2)
            {
                all[i]->setPosition("");
                break;
            }
        }*/
        // redraw all pieces on the board
        drawPieces(f, m, all, 32);
    }
}

void Piece::drawPieces(fstream& file, map<string, int>& m, Piece **pieces,
        short iters)
{
    for (short i = 0; i < iters; i++)
    {
        file.seekp(m[pieces[i]->getPosition()]);
        file.write(pieces[i]->getSymbol().c_str(), 1);
    }
}

// removes occupied positions from a vector of considered moves
void Piece::removeOccs(vector<string> v, Piece **all)
{
    for (short i = 0; i < 32; i++)
    {
        for (short j = 0; j < v.size(); j++)
        {
            if (all[i]->getPosition() == v[j])
            {
                swap(v[j], v.back());
                v.pop_back();
            }
        }
    }    
}

bool Piece::isOcc(Piece **all, string s)
{
    for (short i = 0; i < 32; i++)
    {
        if (all[i]->getPosition() == s)
        {
            return true;
        }
    }
    return false;
}

char Piece::valids[16] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    '0', '1', '2', '3', '4', '5', '6', '7'
 };
