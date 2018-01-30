//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #1: Multiples of 3 and 5                                              //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

inline long sum_n(long n){
    return (n*(n+1))/2;
}

int main() {
    int T;
    long N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << 3*sum_n((N-1)/3) + 5*sum_n((N-1)/5)-15 * sum_n((N-1)/15)
                  << std::endl;
    }
}
