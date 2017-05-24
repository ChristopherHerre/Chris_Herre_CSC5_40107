
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
    vector<string> getAvailPositions(Piece **all)
    {
        vector<string> v;
        stringstream ss;
        // handle uppercase side movements
        if (!islower(this->symbol[0]))
        {
            // SW diag
            ss << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1] - 1);
            v.push_back(ss.str());
            // SE diag
            stringstream ss3;
            ss3 << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1] + 1);
            v.push_back(ss3.str());
            // straight South
            stringstream ss4;
            ss4 << static_cast<char>(position[0] + 1)
                    << static_cast<char>(position[1]);
            v.push_back(ss4.str());
            if (!isOcc(all, ss4.str()))
            {
                // on pawns first move, it can move two spaces straight
                if (position[0] == 'B')
                {
                    // straight South x2
                    stringstream ss4;
                    ss4 << static_cast<char>(position[0] + 2)
                            << static_cast<char>(position[1]);
                    v.push_back(ss4.str());
                }
            }
        }
        // handle lowercase side movements
        if (islower(this->symbol[0]))
        {
            // NW diag
            stringstream ss1;
            ss1 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1] - 1);
            v.push_back(ss1.str());
            // NE diag
            stringstream ss2;
            ss2 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1] + 1);
            v.push_back(ss2.str());
            // straight North
            stringstream ss5;
            ss5 << static_cast<char>(position[0] - 1)
                    << static_cast<char>(position[1]);
            v.push_back(ss5.str());
            if (!isOcc(all, ss5.str()))
            {
                // on pawns first move, it can move two spaces straight
                if (position[0] == 'G')
                {
                    // straight North x2
                    stringstream ss5;
                    ss5 << static_cast<char>(position[0] - 2)
                            << static_cast<char>(position[1]);
                    v.push_back(ss5.str());
                }
            }
        }

        // remove elements containing invalid chars
        /*for (string s : v)
        {
            //cout << "sssss " << s << " ";
            cout << s.find_first_not_of(valids) << endl;
            if (s.find_first_not_of(valids) > -1)
            {
                //cout << find(v.begin(), v.end(), s) << " "
                //       << v.at(find(v.begin(), v.end(), s)) << endl;
                swap(v.at(find(v.begin(), v.end(), s)), v.back());
                v.pop_back();
            }
        }*/
        // Remove occupied positions from the available positions
        removeOccs(v, all);
        return v;
    }
private:

};

#endif /* PAWN_H */

