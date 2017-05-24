
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
        // diag
        stringstream ss;
        ss << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss.str());
        // diag
        stringstream ss1;
        ss1 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] - 1);
        v.push_back(ss1.str());
        // diag
        stringstream ss2;
        ss2 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss2.str());
        // diag
        stringstream ss3;
        ss3 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1] + 1);
        v.push_back(ss3.str());
        stringstream ss4;
        ss4 << static_cast<char>(position[0] + 1)
                << static_cast<char>(position[1]);
        if (isOcc(all, ss4.str()))
        {
            v.push_back(ss4.str());
        }
        stringstream ss5;
        ss5 << static_cast<char>(position[0] - 1)
                << static_cast<char>(position[1]);
        if (isOcc(all, ss4.str()))
        {
            v.push_back(ss5.str());
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

