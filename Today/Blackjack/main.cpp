/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on April 15, 2017, 12:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Notice - Saving player banks to binary files was taken out last minute due
 * to time constraints. I had many problems that were crashing my entire
 * program.
 * 
 * Everything else should be covered. 
 */
struct Card
{
    short cNumber, suit, rank;
    
    char getSuit()
    {
        if (cNumber < 13) return 'S';
        else if (cNumber < 26) return 'D';
        else if (cNumber < 39) return 'C';
        else return 'H';
    }
    
    char getRank()
    {
        char fv[] = {'A','2','3','4','5','6','7','8','9', 'T','J','Q','K'};
        return fv[cNumber % 13];
    }
    
    short getVal()
    {
        char rank = getRank();
        switch (rank)
        {
            case 'A':
                return static_cast<short>(1);
            case 'T':
            case 'J':
            case 'Q':
            case 'K':
                return static_cast<short>(10);
        }
        return static_cast<short>(rank - 48);
    }
    
    string toString()
    {
        string s = "";
        s += getRank();
        s += getSuit();
        return s;
    }
};

struct Player
{
    Card card1, card2;
    vector<Card> hits;
    short score = 0, bet = 0, bank = 2500;
};

void bet(Player *players, Card *deck, short pCount);
Card *initDeck();
void shuffle(Card *deck);
void printDeck(Card *deck);
void deal(Card *deck, Player *players, vector<short>& dealt, short pCount);
void move(Player *players, Card *deck, vector<short>& dealt, short pCount,
        short lastPlayer);
void hit(Card *deck, Player *players, short pId, vector<short>& dealt);
void avoidDupes(vector<short>& dealt, short& ran1, short& ran2);

const short DECK_SIZE = 52;

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    Card *deck = initDeck();
    shuffle(deck);
    short pCount = 0;
    cout << "How many players are playing?" << endl;
    cin >> pCount;
    if (pCount > 5)
    {
        delete[] deck;
        cout << "Maximum allowed players is 5. Goodbye." << endl;
        exit(0);
    }
    Player *players = new Player[pCount];
    bet(players, deck, pCount);
    // an array for the indices of the deck that have already been dealt
    vector<short> dealt;
    deal(deck, players, dealt, pCount);
    cout << endl;
    move(players, deck, dealt, pCount, -1);
    for (short i = 0; i < pCount; i++)
    {
        players[i].hits.clear();
    }
    dealt.clear();
    delete[] players;
    //printDeck(deck, SIZE);
    return 0;
}

void bet(Player *players, Card *deck, short pCount)
{
    for (short i = 0; i < pCount; i++)
    {
        if (i == pCount - 1)
        {
            cout << "Skipping the bet for the dealer." << endl;
            continue;
        }
        cout << "Player " << i + 1 << " place your bet: $";
        cin >> players[i].bet;
        if (players[i].bet > players[i].bank)
        {
            cout << "Player " << i + 1 <<
                    " does not have enough bank for their bet!" << endl;
            delete[] players;
            delete[] deck;
            exit(0);
        }
        players[i].bank -= players[i].bet;
        cout << "Player " << i + 1 << " bet $" << players[i].bet << "." << endl;
        cout << "Player " << i + 1 << " bank=$" << players[i].bank << "." << endl;
    }
    cout << endl;
}

Card *initDeck()
{
    Card *deck = new Card[DECK_SIZE];
    for (short i = 0; i < DECK_SIZE; i++)
    {
        deck[i].cNumber = i;
    }
    return deck;
}

void shuffle(Card *deck)
{
    // shuffle 3 times
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < DECK_SIZE; j++)
        {
            short ran = rand() % 52;
            Card temp = deck[j];
            deck[j] = deck[ran];
            deck[ran] = temp;
        }
    }
}

// not used any more
void printDeck(Card *deck)
{
    for (short i = 0; i < DECK_SIZE; i++)
    {
        cout << i << "]\t" << deck[i].getRank() << deck[i].getSuit()
                << " '" << deck[i].getVal() << "'" << endl;
    }
}

void deal(Card *deck, Player *players, vector<short>& dealt, short pCount)
{
    // give every player 2 cards from the deck
    for (short i = 0; i < pCount; i++)
    {
        short ran1 = rand() % DECK_SIZE;
        short ran2 = rand() % DECK_SIZE;
        avoidDupes(dealt, ran1, ran2);
        // handle the first two cards being dealt
        players[i].card1 = deck[ran1];
        players[i].card2 = deck[ran2];
        players[i].score += deck[ran1].getVal();
        players[i].score += deck[ran2].getVal();
        cout << "card1=" << players[i].card1.toString() << endl;
        cout << "card2=" << players[i].card2.toString() << endl;
        cout << "Player " << i + 1 << " has a score of " << players[i].score
                << endl;
    }
}

void hit(Card *deck, Player *players, short pId, vector<short>& dealt)
{
    short ran1 = rand() % DECK_SIZE;
    short ran2 = rand() % DECK_SIZE;
    avoidDupes(dealt, ran1, ran2);
    // handle cards being dealt after the first 2 cards, AKA hits
    players[pId].hits.push_back(deck[ran1]);
    dealt.push_back(ran1);
    cout << "hit=" << deck[ran1].toString() << endl;
    players[pId].score += deck[ran1].getVal();
    cout << "Player " << pId + 1 << " has a score of " << players[pId].score
            << endl;
    if (players[pId].score > 21)
    {
        cout << "BUST! Player " << pId + 1 << " is out of the round." << endl;
        players[pId + 1].bet = 0;
    }
}

void avoidDupes(vector<short>& dealt, short& ran1, short& ran2)
{
    // reassign ran1 if that index has already been dealt
    // eliminates duplicate cards
    while (find(dealt.begin(), dealt.end(), ran1) != dealt.end())
    {
        ran1 = rand() % DECK_SIZE;
    }
    dealt.push_back(ran1);
    // reassign ran2 if that index has already been dealt
    // brute force until we have found a random index that
    // has not been dealt
    while (find(dealt.begin(), dealt.end(), ran2) != dealt.end())
    {
        ran2 = rand() % DECK_SIZE;
    }
    dealt.push_back(ran2);
    while (ran1 == ran2)
    {
        ran2 = rand() % DECK_SIZE;
    }
}

// keep prompting for user input until player busts or stays
void move(Player *players, Card *deck, vector<short>& dealt, short pCount,
        short lastPlayer)
{
    for (short i = lastPlayer > 0 ? lastPlayer : 0; i < pCount; i++)
    {
        bool isDealer = (i == pCount - 1);
        string input = "";
        while ((players[i].score < 21 && input != "stay")
                || isDealer && players[i].score >= 17)
        {
            if (players[i].score <= 21)
            {
                cout << "### " << (!isDealer ? "PLAYER" : "DEALER") << " "
                        << i + 1 << "'S TURN ###" << endl;
            }
            // if not the dealer, prompt for input
            if (!isDealer)
            {
                cout << "Type 'stay' or 'hit': ";
                cin >> input;
            }
            if (input == "stay")
            {
                cout << "You chose to keep your score of " << players[i].score
                        << " the same and not take a risk." << endl;
                continue;
            }
            // dealer must hit until his score is >= 17
            else if ((isDealer && players[i].score < 17) || input == "hit")
            {
                hit(deck, players, i, dealt);
            }
            // more options coming soon in the next version
            else
            {
                if (isDealer)
                {
                    break;
                }
                cout << "Error! Input is invalid!" << endl;
                move(players, deck, dealt, pCount, i);
                return;
            }
        }
    }
    short numWinners = 0;
    for (short i = 0; i < pCount; i++)
    {
        // player is not the dealer, players score less than 21,
        // and players score equals dealers score
        if (i != pCount - 1 && players[i].score < 21
                && players[i].score == players[pCount - 1].score)
        {
            cout << "Push! No wins or loses for Player " << i + 1 
                    << "." << endl;
            // todo, bet will still be lost below!
            continue;
        }
        // if dealer score is less than player score and player has not bust
        if ((players[pCount - 1].score < players[i].score
                && players[i].score <= 21)
                // if dealer busts and player does not
                || players[pCount - 1].score > 21 && players[i].score <= 21)
        {
            // todo handle a blackjack winnings
            cout << "Player " << i + 1 << " is a winner!" << endl;
            players[i].bet *= 2;
            cout << "Player " << i + 1 << " bet doubled to "
                    << players[i].bet << "." << endl;
            players[i].bank += players[i].bet;
            cout << "Player " << i + 1 << " bank increased to "
                    << players[i].bank << "." << endl;
            players[i].bet = 0;
            cout << "Player " << i + 1 << " bet reset to "
                    << players[i].bet << "." << endl;
            
            numWinners++;
        }
    }
    if (numWinners == 0)
    {
        cout << "Dealer wins." << endl;
        for (short i = 0; i < pCount; i++)
        {
            if (players[i].bet > 0)
            {
                cout << "Player " << i + 1 << " had a bet of "
                        << players[i].bet << ". Now reset to 0." << endl;
                players[i].bet = 0;
            }
        }
    }
}