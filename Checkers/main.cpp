
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
#include <new>

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Piece.h"

/**
 * IMPORTANT NOTICE
 * 
 * If using Windows OS, search for this line and comment it out
 * 
 * m[ss.str()] -= 2 + 4 * letter; //comment this out
 * 
 * The grid system I created will be messed up otherwise and positions
 * will be off!
 */

using namespace std;

void initCoords(map<string, int>& m);
void drawBoard(fstream& newGame, short& col);
void drawPieces(fstream& file, map<string, int>& m, Piece **pieces,
        short iters);
void refreshBoard();
void printSymbol(Piece **all, Piece **type);
void initPieces(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all);
void collectInput(string& input, string& input2);

const string READ = "newgameCopy.txt";
const string WRITE = "newgame.txt";

int main(int argc, char** argv)
{
    map<string, int> m;
    initCoords(m);
    short col = 65;
    refreshBoard();
    Piece **all = new Piece*[32];
    Piece **pawns = new Piece*[16];
    Piece **knights = new Piece*[4];
    Piece **bishops = new Piece*[4];
    Piece **rooks = new Piece*[4];
    Piece **kings = new Piece*[2];
    Piece **queens = new Piece*[2];
    Piece **piece = new Piece*[1];
    // order is important!
    initPieces(pawns, knights, bishops, rooks, kings, queens, all);
    string input, input2;
    fstream game;
    
    game.open(WRITE, ios::in | ios::out);
    if (game.is_open())
    {
        drawPieces(game, m, pawns, 16);
        drawPieces(game, m, knights, 4);
        drawPieces(game, m, bishops, 4);
        drawPieces(game, m, rooks, 4);
        drawPieces(game, m, kings, 2);
        drawPieces(game, m, queens, 2);
        game.seekg(0);
        drawBoard(game, col);
        game.close();
        while (true)
        {
            fstream f;
            collectInput(input, input2);
            // generate new board
            try
            {
                f.open(WRITE, ios::in | ios::out);
                for (short i = 0; i < 32; i++)
                {
                    // if there is a piece at the input pos given
                    if (all[i]->getPosition() == input)
                    {
                        piece[0] = all[i];
                    }
                }
                piece[0]->move(all, f, m, input, input2);
                //delete piece[0];
                //delete[] piece;
                f.seekg(0);
                drawBoard(f, col);
            }
            catch (string e)
            {
                cout << e << endl;
            }
            f.close();
        }
    }
    delete piece[0];
    delete[] piece;
    for (short i = 0; i < 16; i++)
    {
        delete pawns[i];
    }
    delete[] pawns;

    for (short i = 0; i < 4; i++)
    {
        delete knights[i];
    }
    delete[] knights;

    for (short i = 0; i < 2; i++)
    {
        delete kings[i];
    }
    delete[] kings;

    for (short i = 0; i < 2; i++)
    {
        delete queens[i];
    }
    delete[] queens;

    for (short i = 0; i < 4; i++)
    {
        delete rooks[i];
    }
    delete[] rooks;

    for (short i = 0; i < 4; i++)
    {
        delete bishops[i];
    }
    delete[] bishops;
    return 0;
}

void collectInput(string& input, string& input2)
{
    cout << "Enter the coordinates of the piece you wish to move." << endl;
    cout << "Example: A1-H7." << endl;
    cout << "input: ";
    getline(cin, input);
    cout << "Enter the coordinates of the destination space." << endl;
    cout << "input: ";
    getline(cin, input2);
}

void printSymbol(Piece **all, Piece **type, short i, short index, short half)
{
    cout << type[i]->getPosition() << " ";
    if (i < half)
    {
        type[i]->setSymbol(toupper(type[i]->getSymbol()[0]));
        cout << type[i]->getSymbol()[0];
    }
    else
    {
        cout << type[i]->getSymbol()[0];
    }
    cout << endl;
    all[index + i] = type[i];
}

// Initialize all pieces in the arrays. Print their symbols onto the board.
void initPieces(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all)
{
    for (short i = 0; i < 16; i++)
    {
        stringstream ss;
        ss << (i < 8 ? "B" : "G") << (i < 8 ? i : i - 8);
        pawns[i] = new Pawn(ss.str());
        printSymbol(all, pawns, i, 0, 8);
    }
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 2 : 5);
        knights[i] = new Knight(ss.str());
        printSymbol(all, knights, i, 16, 2);
    }
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 1 : 6);
        bishops[i] = new Bishop(ss.str());
        printSymbol(all, bishops, i, 16 + 4, 2);
    }
    for (short i = 0; i < 4; i++)
    {
        stringstream ss;
        ss << (i < 2 ? "A" : "H") << (i % 2 == 0 ? 0 : 7);
        rooks[i] = new Rook(ss.str());
        printSymbol(all, rooks, i, 16 + 4 + 4, 2);
    }
    for (short i = 0; i < 2; i++)
    {
        stringstream ss;
        ss << (i < 1 ? "A" : "H") << 3;
        kings[i] = new King(ss.str());
        printSymbol(all, kings, i, 16 + 4 + 4 + 4, 1);
    }
    for (short i = 0; i < 2; i++)
    {
        stringstream ss;
        ss << (i < 1 ? "A" : "H") << 4;
        queens[i] = new Queen(ss.str());
        printSymbol(all, queens, i, 16 + 4 + 4 + 4 + 2, 1);
    }
    cout << "---------------" << endl;
    for (short i = 0; i < 32; i++)
    {
        cout << all[i]->getPosition() << " " << all[i]->getSymbol() << endl;
    }
}

// rewrite the board from a read-only file containing
// the blank map with no pieces
void refreshBoard()
{
    fstream newGame;
    newGame.open(READ, ios::in);
    newGame.seekg(0);
    fstream newGameOut;
    newGameOut.open(WRITE, ios::out | ios::trunc);
    newGameOut.seekp(0);
    string l;
    for (short j = 0; getline(newGame, l); j++)
    {
        newGameOut << l << endl;
    }
    newGameOut.close();
    newGame.close();
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
// grid square. A0 = square 1, H7 = square 64, representing an 8x8 grid.
void initCoords(map<string, int>& m)
{
    for (short letter = 0; letter < 8; letter++)
    {
        for (short num = 0; num < 8; num++)
        {
            stringstream ss;
            ss << static_cast<char>(letter + 65) << num;
            m[ss.str()] = 105 + (6 * num) + (204 * letter);
            //m[ss.str()] -= 2 + 4 * letter; // COMMENT THIS LINE FOR WINDOWS OS
        }
    }
}