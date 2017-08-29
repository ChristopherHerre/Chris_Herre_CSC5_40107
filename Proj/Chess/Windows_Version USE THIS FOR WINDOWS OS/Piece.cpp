
/* 
 * File:   Piece.cpp
 * Author: chris
 * 
 * Created on May 19, 2017, 8:51 PM
 */

#include "Piece.h"

/**
 * Construct a Piece at a given position coordinate.
 * @param position
 */
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

/**
 * Change the position of a Piece inside the game file.
 * @param all The 32 Pieces.
 * @param f The file to write to.
 * @param m The coordinates map.
 * @param input The selected position.
 * @param input2 The destination position.
 */
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

/**
 * Write a number of Pieces to the game file. Ignore if Piece was captured.
 * @param file The game file.
 * @param m The coordinates map.
 * @param pieces The Pieces to draw.
 * @param iters The number of Pieces.
 */
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

/**
 * Check if a position is occupied.
 * @param all The 32 Pieces.
 * @param s The position to check.
 * @return True if position is occupied. False otherwise.
 */
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

/**
 * Depreciated.
 */
char Piece::valids[16] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    '0', '1', '2', '3', '4', '5', '6', '7'
};

/**
 * Check if a position is invalid.
 * @param p The position string.
 * @return True if the Piece is out of range of A-H, 0-7.
 */
bool invalid(string p)
{       
    return p[0] < 'A' || p[0] > 'H' || p[1] < '0' || p[1] > '7';
}

/**
 * Removes all invalid positions. See "bool invalid(string p)" for details.
 * @param v The vector containing valid and invalid positions.
 */
void Piece::removeInvalids(vector<string>& v)
{
    v.erase(remove_if(v.begin(), v.end(), invalid), v.end());
}

/**
 * Remove positions where our teams pieces are.
 * @param all The 32 Pieces.
 * @param v The vector containing positions of our team and enemies.
 */
void Piece::rmvSameSymb(Piece **all, vector<string>& v)
{     
    for (short i = 0; i < v.size(); i++)
    {
        string s = v.at(i);
        Piece* p = getPieceForPos(all, s);
        if (p == NULL)
            continue;
        if ((isupper(p->getSymbol()[0]) && isupper(this->getSymbol()[0]))
                || (islower(p->getSymbol()[0])
                        && islower(this->getSymbol()[0])))
        {
            swap(v.at(i), v.back());
            v.pop_back();
            i = 0;
        }
    }
}

/**
 * Gets a Piece given a position.
 * @param all The 32 Pieces.
 * @param s The position string.
 * @return The Piece at the specified position, or NULL.
 */
Piece* Piece::getPieceForPos(Piece **all, string s)
{
    for (short i = 0; i < 32; i++)
    {
        Piece* p = all[i];
        if (p->getPosition() == s)
        {
            return p;
        }
    }
    return NULL;
}