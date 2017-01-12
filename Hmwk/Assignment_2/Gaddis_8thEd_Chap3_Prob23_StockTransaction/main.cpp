/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 9, 2017, 12:24 PM
 * 
 * 23. Stock Transaction Program
 * Last month Joe purchased some stock in Acme Software, Inc.
 * Here are the details of
 * the purchase:
 * - The number of shares that Joe purchased was 1,000.
 * - When Joe purchased the stock, he paid $45.50 per share.
 * - Joe paid his stockbroker a commission that amounted to 2%
 * of the amount he paid for the stock.
 * 146 Chapter 3 Expressions and Interactivity
 * Programming Challenges 147
 * Two weeks later Joe sold the stock. Here are the details of the sale:
 * - The number of shares that Joe sold was 1,000.
 * - He sold the stock for $56.90 per share.
 * - He paid his stockbroker another commission that amounted to 2% of the
 * amount he received for the stock.
 * Write a program that displays the following information:
 * - The amount of money Joe paid for the stock.
 * - The amount of commission Joe paid his broker when he bought the stock.
 * - The amount that Joe sold the stock for.
 * - The amount of commission Joe paid his broker when he sold the stock.
 * - Display the amount of profit that Joe made after selling his stock
 * and paying the two commissions to his broker. (If the amount of profit
 * that your program displays is a negative number, then Joe lost money
 * on the transaction.) 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // the amount of shares Joe bought
    short nShares = 1000;
    // the original stock price when Joe decided to buy
    float purchPrice = 45.50f;
    // the percentage of commission Joe must pay his broker
    float com = 0.02f;
    // the amount Joe paid to buy the stocks
    float amtPaid = nShares * purchPrice;
    
    // the new stock price when Joe decided to sell
    float soldPrice = 56.90f;
    // the amount Joe received for selling his shares
    float amtSold = nShares * soldPrice;
    
    cout << "Joe paid $" << amtPaid << " to purchase the stocks." << endl;
    cout << "Joe's broker was paid $" << amtPaid * com
            << " in commission when Joe bought the stocks." << endl;
    cout << "Joe sold the stock for $" << amtSold << "." << endl;
    cout << "Joe's broker was paid $" << amtSold * com
            << " in commission when Joe sold the stocks." << endl;
    cout << "Joe made a profit of $" << (amtSold - amtPaid)
            - (amtSold * com + amtPaid * com) << ", taking into account both "
            "of the broker's commissions." << endl;
    return 0;
}