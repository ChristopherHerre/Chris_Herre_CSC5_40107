/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 9, 2017, 10:19 AM
 * 
 * 24. Word Game
 * Write a program that plays a word game with the user.
 * The program should ask the user to enter the following:
 * His or her name
 * His or her age
 * The name of a city
 * The name of a college
 * A profession
 * A type of animal
 * A pet’s name
 * 
 * After the user has entered these items, the program should
 * display the following story, inserting the user’s input into
 * the appropriate locations:
 * 
 * There once was a person named NAME who lived in CITY . At the
 * age of AGE, NAME went to college at COLLEGE. NAME graduated and
 * went to work as a PROFESSION. Then, NAME adopted a(n) ANIMAL
 * named PETNAME. They both lived happily ever after!
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    string name;
    string city;
    string college;
    string profession;
    string animal;
    string petName;
    short age;
    
    // prompt user for their name
    cout << "Enter your name:";
    // store their name in a string variable
    getline(cin, name);
    
    // prompt user for their age
    cout << "How old are you, " << name << "?:";
    // store their age in a short variable
    cin >> age;
    // we must use cin.ignore() after cin >> x to avoid line skipping bug
    // this is because we are also using getline which causes problems when
    // used with cin >> x.
    cin.ignore();
    
    
    // prompt the user for their city of residence
    cout << "What city do you live in?:";
    // store their city of residence in a string variable
    getline(cin, city);
    
    // prompt the user for the name of their school
    cout << "Enter the name of your college/university:";
    // store their school in a string variable
    getline(cin, college);
    
    // prompt the user for their profession
    cout << "Enter your profession:";
    // store their profession in a string variable
    getline(cin, profession);
    
    // prompt the user for their animal
    cout << "Enter the type of animal you have:";
    // store the animal in a string variable
    getline(cin, animal);
    
    // prompt the user for the name of their pet
    cout << "Enter the name of your pet:";
    // store the name of the pet in a string variable
    getline(cin, petName);
    
    // create a new line
    cout << endl;
    
    // display all the variables declared above as a multi-line string output
    cout << "There once was a person named " << name << " who lived in "
                << city << ".\n"
            "At the age of " << age << ", " << name << " went to college at "
                << college << ". " << name << "\n"
            "graduated and went to work as a " << profession << ". Then, "
                << name << " adopted\n"
            "a(n) " << animal << " named " << petName
                << ". They both lived happily ever after!"
           << endl;
    return 0;
}
