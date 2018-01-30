//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #6: Sum square difference                                             //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

unsigned long long square (unsigned long long n){
    return n*n;
}

unsigned long long sum_to_n_squared (unsigned long long n){
    return square((n*(n+1))/2);
}

unsigned long long sum_of_squares (unsigned long long n){
    return (n*(n+1)*(2*n+1))/6;
}

int main() {
    int T;
    unsigned long long N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        std::cout << sum_to_n_squared(N) - sum_of_squares(N) << std::endl;
    }
}
