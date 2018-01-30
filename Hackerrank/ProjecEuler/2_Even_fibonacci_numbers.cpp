//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #2: Even fibonacci numbers                                            //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <utility>

int main() {
    unsigned T;
    unsigned long N, sum, x1, x2;

    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        sum = 10;
        x1 = 21;
        x2 = 34;

        while (x2 <= N){
            sum += x2;
            x1 += x2;
            x2 += x1;
            x1 += x2;
            std::swap(x1, x2);
        }

        std::cout << sum << std::endl;
    }
}
