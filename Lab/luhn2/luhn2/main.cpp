
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 9, 2017, 1:20 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

enum CrdCard
{
    AMERICAN_EXPRESS,
    VISA,
    MASTER_CARD,
    DISCOVER,
    ALL 
};

void luhn(string, short);
string genCC(CrdCard, short&);
short stringToNumber(char);

int main(int argc, char** argv)
{
    srand(static_cast<unsigned int>(time(0)));
    short ran = static_cast<short>(rand() % 5);
    CrdCard card;
    
    switch (ran)
    {
        case 0:
            card = AMERICAN_EXPRESS;
            break;
        case 1:
            card = DISCOVER;
            break;
        case 2:
            card = MASTER_CARD;
            break;
        case 3:
            card = VISA;
            break;
        case 4:
            card = ALL;
            break;
    }
    
    short len = 0;
    string s = genCC(card, len);
    cout << "string length: " << s.length() << "\ts= " << s << endl;
    luhn(s, len);
    return 0;
}

string genCC(CrdCard c, short& len)
{
    string start = "";
    string cc;
    
    switch (c)
    {
        case AMERICAN_EXPRESS:
            len = 15;
            start = (rand() % 2 + 1 == 1 ? "34" : "37");
            
            cout << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
        case VISA:
            len = rand() % 2 + 1 == 1 ? 13 : 16;
            start = "4";
            
            cout << "card number length: " << len << "\tprefix: " << start
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
            
            cout << "card number length: " << len << "\tprefix: " << start
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
            cout << "card number length: " << len << "\tprefix: " << start
                    << endl;
            break;
        case ALL:
            // not sure how to handle?
            cout << "Error - The ALL option is not yet handled!" << endl;
            break;
    }
    
    // according to the wikipedia page, prepending a 0 to an odd-length
    // credit card number will allows the number to be processed from left to
    // right
    if (len % 2 != 0)
    {
        cc += '0';
    }
    cc += start;
    
    for (int i = start.size(); i < len; i++)
    {
        short c = rand() % 10;
        cc += static_cast<char>(c + 48);
        
    }
    return cc;
}

void luhn(string number, short len)
{
    
    // the 3rd line that shows the sums
    short result[20] = {};
    
    // tab each number in the array
    for (int i = 0; i < len; i++)
    {
        cout << number[i] << "\t";
    }
    
    cout << "x" << endl;
    
    for (int i = 0; i < len; i++)
    {
        short sum = 0;
        // converts a string into a short
        short num = stringToNumber(number[i]);
        
        // every other number
        if (i % 2 != 0)
        {
            // double and display every other number
            short x2 = num * 2;
            cout << x2 << "\t";
            
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
            cout << num << "\t";
            result[i] = num;
        }
    }
    
    cout << "x" << endl;
    
    short total = 0;
    short checkDigit = -1;
    
    // add up the total of the sums
    for (int i = 0; i < len; i++)
    {
        cout << result[i] << "\t";
        total += result[i];
    }
    // print the total of the sums
    cout << total << endl;
    // print the check digit
    cout << "check digit x = " << total * 9 % 10;
}

// example: converts a string "1" to a short 1
short stringToNumber(char s)
{
    if (s == '1')
    {
        return 1;
    }
    else if (s == '2')
    {
        return 2;
    }
    else if (s == '3')
    {
        return 3;
    }
    else if (s == '4')
    {
        return 4;
    }
    else if (s == '5')
    {
        return 5;
    }
    else if (s == '6')
    {
        return 6;
    }
    else if (s == '7')
    {
        return 7;
    }
    else if (s == '8')
    {
        return 8;
    }
    else if (s == '9')
    {
        return 9;
    }
    return -1;
}

void flipDigit()
{
    
}