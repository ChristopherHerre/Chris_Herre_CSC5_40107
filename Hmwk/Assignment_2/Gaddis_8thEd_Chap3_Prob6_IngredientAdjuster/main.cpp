
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 9, 2017, 5:11 PM
 * 
 * 6. Ingredient Adjuster
 * A cookie recipe calls for the following ingredients:
 * • 1.5 cups of sugar
 * • 1 cup of butter
 * • 2.75 cups of flour
 * The recipe produces 48 cookies with this amount of the ingredients. Write
 * a program that asks the user how many cookies he or she wants to make, and
 * then displays the number of cups of each ingredient needed for the specified
 * number of cookies.
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
   // cups of sugar per 48 cookies
   float cupsSugar = 1.5f;
   // cups of butter per 48 cookies
   float cupsButter = 1.0f;
   // cups of flour per 48 cookies
   float cupsFlour = 2.75;
   // user input variable
   short cookies;
   
   cout << "How many cookies do you want to make?: ";
   cin >> cookies;
   
   // divide by 48 to get the amount needed per cookie
   // multiply times cookies and display
   cout << "You'll need " << cupsSugar / 48 * cookies << " cups of sugar, ";
   cout << cupsButter / 48 * cookies << " cups of butter, and ";
   cout << cupsFlour / 48 * cookies << " cups of flour. "<< endl;
   return 0;
}

