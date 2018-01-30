//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #3: Largest prime factor                                              //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>

int main() {
    int T;
    unsigned long N, count, top;

    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        while (true){
            count = 2;
            top = std::sqrt(N) + 1;

            while (count<top && (N%count)!=0) ++count;

            if (count==top){
                break;
            }

            N /= count;
        }

        std::cout << N << std::endl;
    }
}
