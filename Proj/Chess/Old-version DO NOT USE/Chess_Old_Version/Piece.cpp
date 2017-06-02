
/* 
 * File:   Piece.cpp
 * Author: chris
 * 
 * Created on May 19, 2017, 8:51 PM
 */

#include "Piece.h"

Piece::Piece(string position)
{
    this->position = position;
}

Piece::~Piece() { }

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
    f.seekp(m[input2]);
    f.write(this->getSymbol().c_str(), 1);
    f.seekp(m[input]);
    f.write(" ", 1);
    // capture
    for (short i = 0; i < 32; i++)
    {
        if (all[i]->getPosition() == input2)
        {
            all[i]->setPosition("CAP");
            break;
        }
    }
    setPosition(input2);
    // redraw all pieces on the board
    drawPieces(f, m, all, 32);
}

void Piece::drawPieces(fstream& file, map<string, int>& m, Piece **pieces,
        short iters)
{
    for (short i = 0; i < iters; i++)
    {
        // has a piece been captured? don't draw
        if (pieces[i]->getPosition() != "CAP")
        {
            file.seekp(m[pieces[i]->getPosition()]);
            file.write(pieces[i]->getSymbol().c_str(), 1);
        }
    }
}

// check if a position is occupied
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

void Piece::removeInvalids(vector<string>& v)
{
    for (short i = 0; i < v.size(); i++)
    {
        string s = v.at(i);
        size_t found = s.find_first_not_of(valids);
        if (found != string::npos)
        {
            cout << v.at(i) << endl;
            swap(v.at(i), v.back());
            v.pop_back();
        }
    }
}

// remove positions where our teams pieces are
void Piece::rmvSameSymb(Piece **all, vector<string>& v)
{
    for (short i = 0; i < 32; i++)
    {
        if (all[i]->symbol == this->getSymbol())
        {
            swap(v.at(i), v.back());
            v.pop_back();
        }
    }
}