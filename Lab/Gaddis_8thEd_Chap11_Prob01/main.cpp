
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on March 28, 2017, 2:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct MovieData
{
    string title, director, release;
    float duration;
    double prodCost, yr1Rev;
};

void printInfo(MovieData);

int main(int argc, char** argv) {
    MovieData data1 = { "Forrest Gump", "Robert Zemeckis", "July 6, 1994", 3.54, 5, 2 };
    MovieData data2 = { "The Dark Knight", "Christopher Nolan", "July 18, 2008", 2.32, 180000000, 533345358 };
    
    printInfo(data1);
    printInfo(data2);
    return 0;
}

void printInfo(MovieData data)
{
    cout << left << setw(20) << "Film:" << data.title << endl;
    cout << left << setw(20) << "Directed by:" << data.director << endl;
    cout << left << setw(20) << "Released on:" << data.release << endl;
    cout << left << setw(20) << "Duration:" << data.duration  << " hours"
            << endl;
    cout << left << setw(20) << "1st Year Profit:"
            << data.yr1Rev - data.prodCost << endl;
    cout << endl;
}
