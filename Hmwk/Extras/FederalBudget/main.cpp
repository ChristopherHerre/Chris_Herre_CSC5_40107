
/* 
 * File:   main.cpp
 * Author: Chris Herre
 *
 * Created on January 10, 2017, 11:22 AM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    // https://cit.com/thought-leadership/
    // us-defense-spending-industry-outlook/?
    // cmp=paidsearch&gclid=CPmllfC1uNECFQRsfgodj-cAEA&jcpid=
    // 8a8ae4cd56581431015659d1200a185b&jsf=5ec7b876-08cf-488f-876c-
    // 21ae0d1e84e9:35584
    float milBudget = 5.08e11f,
           // http://federal-budget.insidegov.com/l/119/2016-Estimate
           fedBudget = 3.54e12f;

    // times by 100 to get the percentage
    cout << "The military budget is: " << (milBudget / fedBudget) * 100
            << "% of the federal budget." << endl;
    return 0;
}
