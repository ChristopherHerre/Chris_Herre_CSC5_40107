/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 9, 2017, 1:20 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

enum CrdCard
{
    AMERICAN_EXPRESS,
    VISA,
    MASTER_CARD,
    DISCOVER
};

short luhn(string, short, ofstream&);
string genCC(CrdCard, short&, ofstream&);
short charToNumber(char);
void transpose(string&, ofstream&);
bool validCC(short, short, short, int&, int&, ofstream&);
CrdCard getCardType(short);
void flipDigit(string& cc, ofstream& out);

int main(int argc, char** argv)
{
    ofstream out;
    out.open("output.txt");
    srand(static_cast<unsigned int>(time(0)));
    int valids = 0;
    int invalids = 0;
    cout << "This program will transpose 2 digits and flip 2 digits." << endl;
    cout << "Starting file output to output.txt . . ." << endl;
        
    for (int i = 0; i < 10000; i++)
    {
        short ran = static_cast<short>(rand() % 4);
        CrdCard card = getCardType(ran);
        short len = 0;
        out << endl;
        string s = genCC(card, len, out);
        out << "string length: " << s.length() << "\ts= " << s << endl;
        short luhnFirst = luhn(s, len, out);
        transpose(s, out);
        out << "string length: " << s.length() << "\ts= " << s << endl;
        short luhnSecnd = luhn(s, len, out);
        out << "Start flipping . . ." << endl;
        // flip first digit
        flipDigit(s, out);
        // flip a 2nd digit
        flipDigit(s, out);
        short luhnThird = luhn(s, len, out);
        bool valid = validCC(luhnFirst, luhnSecnd, luhnThird, valids, invalids,
                out);
        out << (valid ? "true" : "false") << endl;
    }
    // file out
    out << left << setw(20) << "\nValids:" << valids << endl;
    out << left << setw(20) << "Invalids:" << invalids << endl;
    // console out
    cout << left << setw(20) << "\nValids:" << valids << endl;
    cout << left << setw(20) << "Invalids:" << invalids << endl;
    out.close();
    cout << "Done! " << endl;
    return 0;
}

// validate the cc #s by performing the luhn algorithm on the original cc number
// and the transposed version of the cc number. If the check sums are equal,
// then the cc number is valid.
bool validCC(short luhnFirst, short luhnSecnd, short luhnThird, int& valids,
        int& invalids, ofstream& out)
{
    if (luhnFirst == luhnSecnd && luhnFirst == luhnThird)
    {
        valids++;
        out << "Adding to valids. Valids:\t" << valids << endl;
        return true;
    }
    else
    {
        invalids++;
        out << "Adding to invalids. Invalids:\t" << invalids << endl;
    }
    return false;
}

// generate a variable length cc number given a CrdCard.
string genCC(CrdCard c, short& len, ofstream& out)
{
    string start = "";
    string cc;
    
    switch (c)
    {
        case AMERICAN_EXPRESS:
            len = 15;
            start = (rand() % 2 + 1 == 1 ? "34" : "37");
            out << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
        case VISA:
            len = rand() % 2 + 1 == 1 ? 13 : 16;
            start = "4";
            out << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
        case MASTER_CARD:
            len = rand() % 2 + 1 == 1 ? 16 : 19;
            switch (rand() % 5 + 1)
            {
                case 1:
                    start = "51";
                    break;
                case 2:
                    start = "52";
                    break;
                case 3:
                    start = "53";
                    break;
                case 4:
                    start = "54";
                    break;
                case 5:
                    start = "55";
                    break;
            }
            out << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
        case DISCOVER:
            len = 16;
            
            switch (rand() % 10 + 1)
            {
                case 1:
                    start = "6011";
                    break;
                case 2:
                    start = "622126";
                    break;
                case 3:
                    start = "622925";
                    break;
                case 4:
                    start = "644";
                    break;
                case 5:
                    start = "645";
                    break;
                case 6:
                    start = "646";
                    break;
                case 7:
                    start = "647";
                    break;
                case 8:
                    start = "648";
                    break;
                case 9:
                    start = "649";
                    break;
                case 10:
                    start = "65";
                    break;
            }
            out << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
    }
    
    // according to the Wikipedia page, prepending a 0 to an odd-length
    // credit card number will allow the number to be processed from left to
    // right
    if (len % 2 != 0)
    {
        cc += '0';
    }
    cc += start;
    
    // start at the ending-prefix-index and finish generating
    // the remainder of the cc
    for (int i = start.size(); i < len; i++)
    {
        // random cc digit 0-9
        short c = rand() % 10;
        cc += static_cast<char>(c + 48);
    }
    return cc;
}

// returns the checksum, or x value
short luhn(string number, short len, ofstream& out)
{
    // the 3rd line that shows the sums
    short result[20] = {};
    // tab each number in the array
    for (int i = 0; i < len; i++)
    {
        out << number[i] << "\t";
    }
    out << "x" << endl;
    for (int i = 0; i < len; i++)
    {
        short sum = 0;
        // converts a string into a short
        short num = charToNumber(number[i]);
        
        // every other number
        if (i % 2 != 0)
        {
            // double and display every other number
            short x2 = num * 2;
            out << x2 << "\t";
            
            if (x2 > 9)
            {
                // sum the digits of a number greater than 9
                while (x2 != 0)
                {
                    sum = sum + x2 % 10;
                    x2 = x2 / 10;
                    
                }
                // store the sum in the results array
                result[i] = sum;
            }
            else
            {
                // if less than 9, just display the original
                result[i] = x2;
            }
        }
        else
        {
            // print the numbers from the first line that do not get doubled
            out << num << "\t";
            result[i] = num;
        }
    }
    out << "x" << endl;
    short total = 0;
    short checkDigit = -1;
    // add up the total of the sums
    for (int i = 0; i < len; i++)
    {
        out << result[i] << "\t";
        total += result[i];
    }
    // print the total of the sums
    out << total << endl;
    checkDigit = total * 9 % 10;
    // print the check digit
    out << "check digit x = " << checkDigit << endl;
    return checkDigit;
}

void flipDigit(string& cc, ofstream& out)
{
    out << endl;
    // choose a random index that is not part of the prefix
    // for more accurate results
    short randIdx = (rand() % cc.size() - 6) + 6;
    out << left << setw(10) << "randIdx=" << randIdx << endl;
    out << left << setw(10) << "OG CC:" << cc << endl;
    cc[randIdx] = static_cast<char>((rand() % 10) + 48);
    out << left << setw(10) << "NW CC" << cc << endl;
}

void transpose(string& cc, ofstream& out)
{
    out << endl;
    // transpose a randomly chosen char to its right-adjacent char
    // ex OG CC:       6478301126991215
    // CC:             6478031126991215

    // choose a random index that is not part of the prefix
    // for more accurate results
    short randIdx = (rand() % cc.size() - 6) + 6;
    out << left << setw(10) << "randIdx= " << randIdx << endl;
    char temp = cc[randIdx + 1];
    out << left << setw(10) << "OG CC:" << cc << endl;
    cc[randIdx + 1] = cc[randIdx];
    cc[randIdx] = temp;
    out << left << setw(10) << "NW CC:" << cc << endl;
}

CrdCard getCardType(short ran)
{
    switch (ran)
    {
        case 0:
            return AMERICAN_EXPRESS;
        case 1:
            return DISCOVER;
        case 2:
            return MASTER_CARD;
        case 3:
            return VISA;
    }
}

// example: converts a char '1' to a short 1
short charToNumber(char c)
{
    if (c == '1')
    {
        return 1;
    }
    else if (c == '2')
    {
        return 2;
    }
    else if (c == '3')
    {
        return 3;
    }
    else if (c == '4')
    {
        return 4;
    }
    else if (c == '5')
    {
        return 5;
    }
    else if (c == '6')
    {
        return 6;
    }
    else if (c == '7')
    {
        return 7;
    }
    else if (c == '8')
    {
        return 8;
    }
    else if (c == '9')
    {
        return 9;
    }
    return -1;
}