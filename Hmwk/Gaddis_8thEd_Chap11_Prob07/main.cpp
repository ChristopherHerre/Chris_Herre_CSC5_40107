
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 30, 2017, 1:36 PM
 * 
 * KNOWN PROBLEMS cin & getline is a b!itch!!! Just press enter when it happens.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct Customer
{
    string name, address, city, state, zip, phone, lastPay;
    float balance;
};

void updateRec(Customer&);
void updateSpec(Customer *, short);
void printRec(Customer);
void initRec(Customer *, short);
void doMenu07();
void printAll(Customer *, short);

int main(int argc, char** argv) {
    const short SIZE = 10;
    Customer *data = new Customer[SIZE];
    char c;
    
    do
    {
        doMenu07();
        cin >> c;
        switch (c - 48)
        {
            case 1:
                initRec(data, SIZE);
                break;
            case 2:
                {
                    short idx;
                    cout << "What index would you like to update? ";
                    cin >> idx;
                    updateSpec(data, idx);
                }
                break;
            case 3:
                printAll(data, SIZE);
                break;
        }
    } while (c - 48 > 0 && c - 48 < 10);
    return 0;
}

void doMenu07()
{
    cout << "1) Initialize all records" << endl;
    cout << "2) Update a specified record" << endl;
    cout << "3) Display all records" << endl;
}

// updates a record at a specified index
void updateSpec(Customer *data, short index)
{
    updateRec(data[index]);
    printRec(data[index]);
}

void initRec(Customer *data, short size)
{
    // set initial values for the record for 10 customers
    for (short i = 0; i < size; i++)
    {
        cout << "UPDATING CUSTOMER " << i << endl;
        updateRec(data[i]);
        printRec(data[i]);
    }
}

void updateRec(Customer& cust)
{
    string s = "Enter a new value: ";
    cout << "The current customer name is '" << cust.name << "'. " << s;
    getline(cin, cust.name);
    cin.ignore();
    cin.clear();
    cout << "The current address is '" << cust.address << "'. " << s;
    getline(cin, cust.address);
    cin.ignore();
    cin.clear();
    cout << "The current city is '" << cust.city << "'. " << s;
    getline(cin, cust.city);
    cin.ignore();
    cin.clear();
    cout << "The current state is '" << cust.state << "'. " << s;
    getline(cin, cust.state);
    cin.ignore();
    cin.clear();
    cout << "The current zip code is '" << cust.zip << "'. " << s;
    cin >> cust.zip;
    cin.ignore();
    cin.clear();
    cout << "The current phone number is '" << cust.phone << "'. " << s;
    getline(cin, cust.phone);
    cin.ignore();
    cin.clear();
    cout << "The current date of last payment is '" << cust.lastPay << "'. "
           << s;
    getline(cin, cust.lastPay);
    cin.ignore();
    cin.clear();
    cout << "The current account balance is '" << cust.balance << "'. " << s;
    cin >> cust.balance;
    cin.ignore();
    cin.clear();
    
    if (cust.balance < 1)
    {
        cout << "A negative balance has been entered. Goodbye!" << endl;
        exit(0);
    }
}

void printRec(Customer cust)
{
    cout << left << setw(20) << "Customer name:" << cust.name << endl;
    cout << left << setw(20) << "Address:" << cust.address << endl;
    cout << left << setw(20) << "City:" << cust.city << endl;
    cout << left << setw(20) << "State:" << cust.state << endl;
    cout << left << setw(20) << "Zip code:" << cust.zip << endl;
    cout << left << setw(20) << "Phone #:" << cust.phone << endl;
    cout << left << setw(20) << "Last pay:" << cust.lastPay << endl;
    cout << left << setw(20) << fixed << setprecision(2) << "Balance:"
            << cust.balance << endl;
    cout << endl;
}

void printAll(Customer *data, short size)
{
    for (short i = 0; i < size; i++)
    {
        printRec(data[i]);
    }
}