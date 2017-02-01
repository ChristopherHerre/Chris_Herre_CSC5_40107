
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on February 1, 2017, 1:27 PM
 * 
 * Notice: Use C++ 11 compiler
 * 
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

void displayMenu();

void markup();
float calculateRetail(float, float);

void winningDivision();
float getSales(string);
void findHeighest(float totals[]);

void safestDrivingArea();
int getNumAccidents(string);
void findLowest(short []);

void fallingDist();
float fallingDistance(short);

void displayKEnergy();
float kineticEnergy(float, float);

void displayCelsius();
float celsius(float);

void doCoinToss();
void coinToss();

void doPresentValue();
float presentValue(float, float, short);

void doFutureValue();
float futureValue(float, float, short);

void populationSize();
float getPopSize(int, float, float);

int main(int argc, char** argv) {
    short choice;
    
    do
    {   
        displayMenu();
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                markup();
                break;
            case 2:
                winningDivision();
                break;
            case 3:
                safestDrivingArea();
                break;
            case 4:
                fallingDist();
                break;
            case 5:
                displayKEnergy();
                break;
            case 6:
                displayCelsius();
                break;
            case 7:
                doCoinToss();
                break;
            case 8:
                doPresentValue();
                break;
            case 9:
                doFutureValue();
                break;
            case 10:
                populationSize();
                break;
        }
    } while (choice > 0 && choice <= 10);
    return 0;
}

void displayMenu()
{
    cout << "Welcome to Chris Herre's Assignment 5 Menu!\n" << endl;
    cout << "1) Markup" << endl;
    cout << "2) Winning Division" << endl;
    cout << "3) Safest Driving Area" << endl;
    cout << "4) Falling Distance" << endl;
    cout << "5) Kinetic Energy" << endl;
    cout << "6) Celsius Table" << endl;
    cout << "7) Coin Toss" << endl;
    cout << "8) Present Value" << endl;
    cout << "9) Future Value" << endl;
    cout << "10) Population" << endl;
}

void markup()
{
    float cost, markup;
    cout << fixed << setprecision(2);
    cout << "Enter an item's wholesale cost: ";
    cin >> cost;
    
    // check if cost is negative
    if (cost < 0)
    {
        cout << "Wholesale cost cannot be negative!" << endl;
        // exit early
        return;
    }
    
    cout << "Enter the markup percentage (Ex: 50% = 0.5): ";
    cin >> markup;
    
    // check if markup is negative
    if (markup < 0)
    {
        cout << "Markup percentage cannot be negative!" << endl;
        // exit early
        return;
    }
    
    cout << "Retail price = $" << calculateRetail(cost, markup) << endl;
}

// returns the retail price given cost and markup
float calculateRetail(float cost, float markup)
{
    return cost + (cost * markup);
}

void winningDivision()
{
    const string DIVISIONS[] = 
    { "Northeast", "Southeast", "Northwest", "Southwest" };
    
    // create an array to store the sales of each division
    float sales[4];
    
    // set decimal format
    cout << setprecision(2) << fixed;
    
    // loop for each division name, store as variable d
    int index = 0;
    for (string d : DIVISIONS)
    {
        float s = getSales(d);
        
        // validate s
        if (s == -1)
        {
            break;
        }
        
        // assign this division its sales
        sales[index] = s;
        index++;
    }
    findHeighest(sales);
}

// gets the sales for a given division from the user
float getSales(string div)
{
    float sales;
    cout << "Enter the " << div << " division's quarterly sales: ";
    cin >> sales;
    
    // validate input
    if (sales < 0.00)
    {
        cout << "Sales cannot be negative!" << endl;
        return -1;
    }
    return sales;
}

// prints the highest value given an array reference
void findHeighest(float totals[])
{
    const string DIVISIONS[] = 
    { "Northeast", "Southeast", "Northwest", "Southwest" };
    
    float highest = 0;
    unsigned char highIndex = 0;
    
    // set highest to the highest value in the array
    // loop through every element in the array
    for (int i = 0; i < 4; i++)
    {
        float num = totals[i];
        
        if (num > highest)
        {
            // the index of DIVISIONS that is the winner
            highIndex = i;
            highest = num;
        }
    }
    cout << "Highest grossing division: " << DIVISIONS[highIndex] << " made $"
            << highest << endl;
}

void safestDrivingArea()
{
    const string REGIONS[] = { "north", "south", "east", "west", "central" };
    short numAccidents[5];

    // populate numAccidents array with the return value of getNumAccidents
    // for each region
    for (int i = 0; i < 5; i++)
    {
        numAccidents[i] = getNumAccidents(REGIONS[i]);
    }
    // call findLowest function
    findLowest(numAccidents);    
}

int getNumAccidents(string region)
{
    short accidents;
    
    // prompt user to input the number of accidents for the given region
    cout << "What is the number of automobile accidents in the " << region
            << " region? ";
    cin >> accidents;
    
    // validate input, cannot be negative # of accidents
    if (accidents < 0)
    {
        cout << "Cannot accept an accident number less than 0!" << endl;
        return -1;
    }
    return accidents;
}

void findLowest(short accidents[])
{
    const string REGIONS[] = { "north", "south", "east", "west", "central" };
    // set lowest to a value larger than any inputs to the accidents array
    short lowest = 30000;
    unsigned char lowestIndex = 0;
    
    // loop for each index in our regions array
    for (int i = 0; i < 5; i++)
    {
        if (accidents[i] < lowest)
        {
            lowestIndex = i;
            // reassign lowest to the actual lowest value so far
            // through the loop
            lowest = accidents[i];
        }
    }
    // output which region had the least accidents
    cout << "The " << REGIONS[lowestIndex] << " region had the least amount of"
            " accidents at " << lowest << " accidents last year." << endl;
}

void fallingDist()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "Distance: " << fallingDistance(i) << endl;
    }
    return;   
}

float fallingDistance(short time)
{
    return 0.5 * 9.8 * (time * time);
}

void displayKEnergy()
{
    float mass, vel;
    
    cout << "Enter the objects mass in kg: ";
    cin >> mass;
    
    cout << "Enter the objects velocity in m/s: ";
    cin >> vel;
    
    cout << "Kinetic Energy = " << kineticEnergy(mass, vel) << " Joules"
            << endl;
        
}

float kineticEnergy(float mass, float vel)
{
    return 0.5 * mass * (vel * vel);
}

void displayCelsius()
{
    for (int i = 0; i <= 20; i++)
    {
        cout << i << " Fahrenheit\t=\t" << celsius(i) << " Celsius" << endl;
    }
}

float celsius(float fahr)
{
    return 5/9.0 * (fahr - 32);
}

void doCoinToss()
{
    srand(static_cast<unsigned int>(time(0)));
    
    short flips;
    
    cout << "How many coin tosses? ";
    cin >> flips;
    
    cout << flips << endl;
    
    for (short i = 0; i < flips; i++)
    {
        cout << i + 1 << "\t";
        coinToss();
    }

}

void coinToss()
{
    short toss = (rand() % 2) + 1;
    
    cout << (toss == 1 ? "Heads" : "Tales") << endl;    
}

void doPresentValue()
{
    float p, f, r, years;
    
    cout << "Enter the desired future value: ";
    cin >> f;
    
    cout << "Enter the annual interest rate: ";
    cin >> r;
    
    cout << "Enter the number of years: ";
    cin >> years;
    
    float present = presentValue(f, r, years);
    cout << "Present Value: " << present << endl;    
}

float presentValue(float future, float interestRate, short years)
{
    return future / (pow(1.0 + interestRate, years));
}

void doFutureValue()
{
    float f, p, i;
    short t;
    
    cout << "Enter the accounts present value: ";
    cin >> p;
    
    cout << "Enter the monthly interest rate: ";
    cin >> i;
    
    cout << "Enter the number of months: ";
    cin >> t;
    
    f = futureValue(p, i, t);
    cout << "Future value: " << f << endl;    
}

float futureValue(float p, float i, short t)
{
    return p * pow((1 + i), t);
}

void populationSize()
{
    int p = 0;
    float birth = 0.0f, death = 0.0f;
    short years = 0;
    
    // prompt user to input number of years
    cout << "Enter the number of years: ";
    cin >> years;

    // if years less than 1 then exit
    if (years < 1)
    {
        cout << "Years must be at least 1!" << endl;
        exit(0);        
    } 
    
    for (int i = 0; i < years; i++)
    {
    
        if (p == 0)
        {
            // prompt user for starting size
            cout << "Enter the starting population size: ";
            cin >> p;

            // starting size must be greater than 2 or else exit
            if (p < 2)
            {
                cout << "Starting population size must be greater than 2!"
                        << endl;
                exit(0);
            }
        }

        // prompt user for birth rate
        cout << "Enter the annual birth rate: ";
        cin >> birth;

        // validate birth rate
        if (birth < 1.0)
        {
            cout << "Birth rate must be greater than 1.0!" << endl;
            exit(0);        
        }

        // prompt user for death rate
        cout << "Enter the annual death rate: ";
        cin >> death;

        // validate death rate
        if (death < 1.0)
        {
            cout << "Death rate must be greater than 1.0!" << endl;
            exit(0);        
        }

        // print the population size
        float size = getPopSize(p, birth, death);
        cout << "New population size: " << size << endl;
    }
}

// returns the new population size
float getPopSize(int p, float birthRate, float deathRate)
{
    return p + (birthRate * p) - (deathRate * p);
}
