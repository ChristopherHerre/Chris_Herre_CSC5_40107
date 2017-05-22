
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on May 17, 2017, 11:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Piece.h"

using namespace std;

void initCoords(map<string, int>& m);
void drawBoard(fstream& newGame, short& col);
void drawPieces(fstream& file, map<string, int>& m, Piece **pieces,
        short iters);
int main(int argc, char** argv) {
    map<string, int> m;
    initCoords(m);
    ofstream out;
    out.open("out.txt");
    short col = 65;
    Piece **pawns = new Piece*[16];
    for (short i = 0; i < 16; i++)
    {
        stringstream ss;
        ss << (i < 8 ? "B" : "G") << (i < 8 ? i : i - 8);
        pawns[i] = new Pawn(ss.str());
        cout << pawns[i]->getPosition() << " ";
        if (i < 8)
        {
            pawns[i]->setSymbol(toupper(pawns[i]->getSymbol()[0]));
            cout << pawns[i]->getSymbol()[0];
        }
        else
        {
            cout << pawns[i]->getSymbol()[0];
        }
        cout << endl;
    }
    Piece **knights = new Piece*[4];
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 2 : 5);
        knights[i] = new Knight(ss.str());
        cout << knights[i]->getPosition() << " ";
        if (i < 2)
        {
            knights[i]->setSymbol(toupper(knights[i]->getSymbol()[0]));
            cout << knights[i]->getSymbol()[0];
        }
        else
        {
            cout << knights[i]->getSymbol()[0];
        }
        cout << endl;
    }
    Piece **bishops = new Piece*[4];
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 1 : 6);
        bishops[i] = new Bishop(ss.str());
        cout << bishops[i]->getPosition() << " ";
        if (i < 2)
        {
            bishops[i]->setSymbol(toupper(bishops[i]->getSymbol()[0]));
            cout << bishops[i]->getSymbol()[0];
        }
        else
        {
            cout << bishops[i]->getSymbol()[0];
        }
        cout << endl;
    }
    Piece **rooks = new Piece*[4];
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 0 : 7);
        rooks[i] = new Rook(ss.str());
        cout << rooks[i]->getPosition() << " ";
        if (i < 2)
        {
            rooks[i]->setSymbol(toupper(rooks[i]->getSymbol()[0]));
            cout << rooks[i]->getSymbol()[0];
        }
        else
        {
            cout << rooks[i]->getSymbol()[0];
        }
        cout << endl;
    }
    Piece **kings = new Piece*[2];
    for (short i = 0; i < 2; i++)
    {
        stringstream ss;
        ss << (i < 1 ? "A" : "H") << 3;
        kings[i] = new King(ss.str());
        cout << kings[i]->getPosition() << " ";
        if (i < 1)
        {
            kings[i]->setSymbol(toupper(kings[i]->getSymbol()[0]));
            cout << kings[i]->getSymbol()[0];
        }
        else
        {
            cout << kings[i]->getSymbol()[0];
        }
        cout << endl;
    }
    Piece **queens = new Piece*[2];
    for (short i = 0; i < 2; i++)
    {
        stringstream ss;
        ss << (i < 1 ? "A" : "H") << 4;
        queens[i] = new Queen(ss.str());
        cout << queens[i]->getPosition() << " ";
        if (i < 1)
        {
            queens[i]->setSymbol(toupper(queens[i]->getSymbol()[0]));
            cout << queens[i]->getSymbol()[0];
        }
        else
        {
            cout << queens[i]->getSymbol()[0];
        }
        cout << endl;
    }        
    fstream newGame;
    newGame.open("newgame.txt", ios::in | ios::out);
    if (newGame.is_open())
    {
        drawPieces(newGame, m, pawns, 16);
        drawPieces(newGame, m, knights, 4);
        drawPieces(newGame, m, bishops, 4);
        drawPieces(newGame, m, rooks, 4);
        drawPieces(newGame, m, kings, 2);
        drawPieces(newGame, m, queens, 2);
        newGame.seekg(0);
        drawBoard(newGame, col);
        newGame.close();
        string input, input2;
        cout << "Enter the coordinates of the piece you wish to move." << endl;
        cout << "Example: A1-H7." << endl;
        cout << "input: ";
        getline(cin, input);
        cout << "Enter the coordinates of the destination space." << endl;
        cout << "input: ";
        getline(cin, input2);
        fstream f;
        // generate new board
        try
        {
            f.open("newgame.txt", ios::in | ios::out);
            f.seekp(m[input]);
            f.write(" ", 1);
            f.seekg(0);
            drawBoard(f, col);
        }
        catch (string e)
        {
            cout << e << endl;
        }
        delete[] pawns;
        delete[] knights;
        delete[] kings;
        delete[] queens;
        delete[] rooks;
        delete[] bishops;
        f.close();
        out.close();
    }
    return 0;
}

void drawPieces(fstream& file, map<string, int>& m, Piece **pieces, short iters)
{
    for (short i = 0; i < iters; i++)
    {
        file.seekp(m[pieces[i]->getPosition()]);
        file.write(pieces[i]->getSymbol().c_str(), 1);
    }
}

void drawBoard(fstream& newGame, short& col)
{
    string line;
    for (short j = 0; getline(newGame, line); j++)
    {
        cout << left;
        if (j % 4 == 2)
        {
            cout << setw(5) << static_cast<char>(col++);
        }
        else
        {
            cout << setw(5) << " ";
        }
        for (short i = 0; i < line.length(); i++)
        {
            char c = line.at(i);
            if (c == 'B')
            {
                //m["B" + j] = line.find('B', start + 1);
                //start += line.find('B', start);

                //out << line.find('B', start) << "\t" << endl;
            }
            cout << c;
        }
        cout << endl;
    }
    cout << left << setw(5) << "";
    for (int k = 0; k < 8; k++)
    {
        cout << "   " << k << "  "; 
    }
    cout << endl;
    col = 65;
}

// Map the coordinates on the grid where the letters should appear for each
// grid square. A0 = square 1 - H7 = square 64, representing an 8x8 grid.
void initCoords(map<string, int>& m)
{
    for (short letter = 0; letter < 8; letter++)
    {
        for (short num = 0; num < 8; num++)
        {
            stringstream ss;
            ss << static_cast<char>(letter + 65) << num;
            m[ss.str()] = 105 + (6 * num) + (204 * letter);
            m[ss.str()] -= 2 + 4 * letter;
        }
    }
}