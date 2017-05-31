
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
#include <algorithm>

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Piece.h"
#include "Colors.h"

/**
 * IMPORTANT NOTICE
 * 
 * If using Windows OS, search for this line and comment it out
 * 
 * m[ss.str()] -= 2 + 4 * letter; //comment this out
 * 
 * The grid system I created will be messed up otherwise and positions
 * will be off!
 * 
 * This is because of different encodings on Linux and Windows
 */

using namespace std;

void initCoords(map<string, int>& m);
void drawBoard(fstream& newGame, short& col);
void refreshBoard();
void printSymbol(Piece **all, Piece **type, short i, short index, short half);
void initPieces(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all);
bool proceed(Piece **piece, Piece **all, string& input, short& turn);
void collectInput(string& input, string& input2, Piece **all, Piece **piece,
        fstream& f, map<string, int>& m, short& col, short& turn);
void cleanUp(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all, Piece **piece);
void updateHints(fstream& f, vector<string>& v, map<string, int> m, string val,
        bool print);
bool validateInput(string& input);

const string READ = "newgame.txt";
const string WRITE = "game.txt";

template <class T>
void initPiece(Piece **type, Piece **all, short size)
{
    for (short i = 0; i < size; i++)
    {
        stringstream ss;
        ss << (i < size / 2 ? "B" : "G") << (i < size / 2 ? i : i - size / 2);
        type[i] = new T(ss.str());
        printSymbol(all, type, i, 0, size / 2);
    }
}

template <class T>
void initPiece(Piece **type, Piece **all, short size, short a, short b,
        short index)
{
    for (short i = 0; i < size; i++)
    {
        stringstream ss;
        ss << (i < size / 2 ? "A" : "H") << (i % (size / 2) == 0 ? a : b);
        type[i] = new T(ss.str());
        printSymbol(all, type, i, index, size / 2);
    }
}

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
    initPieces(pawns, knights, bishops, rooks, kings, queens, all);
    short turn = 0;
    string input, input2;
    fstream game;
    game.open(WRITE, ios::in | ios::out);
    if (game.is_open())
    {
        // for the first time, draw pieces onto the board
        Piece::drawPieces(game, m, all, 32);
        game.seekg(0);
        drawBoard(game, col);
        game.close();
        while (kings[0]->getPosition() != "CAP"
                && kings[1]->getPosition() != "CAP")
        {
            fstream f;
            collectInput(input, input2, all, piece, f, m, col, turn);
            f.close();
        }
        if (kings[1]->getPosition() != "CAP")
        {
            cout << BOLDMAGENTA << "MAGENTA" << BLUE
                    << "'s King has been captured!" << RESET << endl;
        }
        else if (kings[0]->getPosition() != "CAP")
        {
            cout << BOLDCYAN << "CYAN" << BLUE
                    << "'s King has been captured!" << RESET << endl;
        }
    }
    //cleanUp(pawns, knights, bishops, rooks, kings, queens, all, piece);
    return 0;
}

void cleanUp(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all, Piece **piece)
{
    delete piece[0];
    delete[] piece;
    for (short i = 0; i < 16; i++)
    {
        delete pawns[i];
    }
    delete[] pawns;

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
        delete knights[i];
    }
    delete[] knights;
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
    for (short i = 0; i < 32; i++)
    {
        delete all[i];
    }
    delete[] all;
}

bool validateInput(string& input)
{
    if (input.size() > 2 || input.size() < 2)
    {
        cout << RED << "Input length is invalid!" << RESET << endl;
        return false;
    }
    if (!isalpha(input[0]) || !isdigit(input[1]))
    {
        cout << RED << "Invalid input syntax! Try A1 or G1 for example."
                << RESET << endl;
        return false;
    }
    if (islower(input[0]))
    {
        input[0] = toupper(input[0]);
    }
    if (input[0] < 65 || input[0] > 72 || input[1] < 48 || input[1] > 55)
    {
        cout << RED << "Invalid input range!" << RESET << endl;
        return false;
    }
    return true;
}

bool proceed(Piece **piece, Piece **all, string& input, short& turn)
{
    if (turn % 2 == 0)
    {
        cout << BLUE << "YOUR TURN " << BOLDMAGENTA << "MAGENTA"
                << BLUE << "." << RESET << endl;
    }
    else
    {
        cout << BLUE << "YOUR TURN " << BOLDCYAN << "CYAN"
                BLUE << "." << RESET << endl;
    }
    cout << "Enter the coordinates of the piece you wish to move." << endl;
    cout << "Example: A1-H7." << endl;
    cout << "input: ";
    getline(cin, input);
    if (!validateInput(input))
        return false;
    piece[0] = NULL;
    for (short i = 0; i < 32; i++)
    {
        // if there is a piece at the input position given
        if (all[i]->getPosition() == input)
            piece[0] = all[i];
    }
    if (piece[0] == NULL)
        return false;
    if (turn % 2 == 0 && islower(piece[0]->getSymbol()[0]))
    {
        cout << "It is " << BOLDMAGENTA << "MAGENTA" << RESET << "'s turn!"
                << endl;
        return false;
    }
    else if (turn % 2 != 0 && isupper(piece[0]->getSymbol()[0]))
    {
        cout << "It is " << BOLDCYAN << "CYAN" << RESET << "'s turn!"
                << endl;
        return false;        
    }
    return true;
}

void collectInput(string& input, string& input2, Piece **all, Piece **piece,
        fstream& f, map<string, int>& m, short& col, short& turn)
{
    const string err = "ERROR! Position you selected not available! Try again.";
    bool add = true;
    if (!proceed(piece, all, input, turn))
        return;
    vector<string> v = piece[0]->getAvailPositions(all);
    sort(v.begin(), v.end());
    if (v.size() < 1)
    {
        f.seekg(0);
        cout << RED << err << RESET << endl;
        add = false;
        return;
    }
    f.open(WRITE, ios::in | ios::out);
    cout << "Available movements:\n";
    updateHints(f, v, m, "*", true);// print each string in v
    Piece::drawPieces(f, m, all, 32);
    cout << endl;
    f.seekg(0);
    if (f.tellg() < 0)
        cout << "ERROR DETECTED!" << endl;
    drawBoard(f, col);
    updateHints(f, v, m, " ", false);
    cout << "Enter the coordinates of the destination space." << endl;
    cout << "input: ";
    getline(cin, input2);
    if (!validateInput(input2))
        return;
    if (find(v.begin(), v.end(), input2) != v.end())
    {
        piece[0]->move(all, f, m, input, input2);
        f.seekg(0);
        drawBoard(f, col);
    }
    else
    {
        updateHints(f, v, m, " ", false);
        f.seekg(0);
        drawBoard(f, col);
        cout << RED << err << RESET << endl;
        add = false;
    }
    if (add)
        turn++;
}

void updateHints(fstream& f, vector<string>& v, map<string, int> m, string val,
        bool print)
{
    short index = 0;
    for (string s : v)
    {
        f.seekp(m[s]);
        f.write(val.c_str(), 1);
        if (print)
            cout << s << (++index % 6 == 0 ? "\n" : "  ");
    }
}

void printSymbol(Piece **all, Piece **type, short i, short index, short half)
{
    if (i < half)
    {
        type[i]->setSymbol(toupper(type[i]->getSymbol()[0]));
    }
    all[index + i] = type[i];
}

// Initialize all pieces in the arrays. Print their symbols onto the board.
void initPieces(Piece **pawns, Piece **knights, Piece **bishops, Piece **rooks,
        Piece **kings, Piece **queens, Piece **all)
{
    initPiece<Pawn>(pawns, all, 16);
    initPiece<Knight>(knights, all, 4, 2, 5, 16);
    initPiece<Bishop>(bishops, all, 4, 1, 6, 16 + 4);
    initPiece<Rook>(rooks, all, 4, 0, 7, 16 + 4 + 4);
    initPiece<King>(kings, all, 2, 3, 3, 16 + 4 + 4 + 4);
    initPiece<Queen>(queens, all, 2, 4, 4, 16 + 4 + 4 + 4 + 2);
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

void drawBoard(fstream& newGame, short& col)
{
    try
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
                if (islower(c))
                {
                    cout << BOLDCYAN << c << RESET;
                }
                else if (isupper(c))
                {
                    cout << BOLDMAGENTA << c << RESET;
                }
                else if (c == '*')
                {
                    cout << BOLDBLUE << c << RESET;
                }
                else
                {
                    cout << c;
                }
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
        newGame.clear();// handle EOF
    }
    catch (string e)
    {
        cout << e << endl;
    }
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
            m[ss.str()] -= 2 + 4 * letter; // COMMENT THIS LINE FOR WINDOWS OS
        }
        // Special value for captured Pieces, not rendered
        m["CAP"] = 0;
    }
}