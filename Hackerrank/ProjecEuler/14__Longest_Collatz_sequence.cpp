//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #14: Longest Collatz sequence                                         //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <utility>

std::vector<unsigned long> cycles(1, 1);

unsigned long collatz_cycles(unsigned long n){
    if (n==1) return 1;
    else if (n%2 == 0) return 1 + collatz_cycles(n/2);
    else return 2 + collatz_cycles((3*n + 1)/2);
}


int main() {
    unsigned long T, N, aux=1;
    std::pair<unsigned long, unsigned long> max{1, aux};
    std::cin >> T;

    while (cycles.size() < 5000000){
        aux = collatz_cycles(cycles.size()+1);

        if (max.second <= aux){
            max.first = cycles.size()+1;
            max.second = aux;
        }

        cycles.push_back(max.first);
    }

    for (unsigned long i=0; i<T; ++i){
        std::cin >> N;
        std::cout << cycles[N-1] << std::endl;
    }
}
