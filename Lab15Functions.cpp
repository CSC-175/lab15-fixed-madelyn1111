/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/
#include <iostream>
#include <limits>


using namespace std;

void getInfo(int & pickFrom, int & numPicks) {


    std::cout << "How many balls (1-12) are in a pool to pick from? ";
    std::cin >> pickFrom;
    while (cin.fail() || pickFrom < 1 || pickFrom > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Input Error! There must be between 1 and 12 balls." << std::endl;
        std::cout << "How many balls (1-12) are in a pool to pick from? ";
        std::cin >> pickFrom;

    }
    std::cout << "How many balls (1-7) will be drawn? ";
    std::cin >> numPicks;
    while (cin.fail() || numPicks < 1 || numPicks > 7) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Input error!" << std::endl;
    }


}


/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.

double factorial(int n);

double computeWays(int n, int k) {
    double ways = (factorial(k) * factorial(n - k)) / factorial(n);
    return ways;
}

// This function computes factorials recursively. It is called by computeWays.
double factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
