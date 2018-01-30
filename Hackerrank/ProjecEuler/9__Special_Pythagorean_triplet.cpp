//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #9: Special Pythagorean triplet                                       //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler009/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
    int T, N, max;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        max = -1;

        if (N%2 == 0 && N>=12){
            for (int a=3; a<N/3; ++a){
                if (((N-a)*(N-a) + a*a)%(2*(N-a)) == 0){
                    int b = ((N-a)*(N-a) + a*a)/(2*(N-a));
                    int c = N-a-b;

                    if (a*b*c > max) max = a*b*c;
                }
            }
        }

        std::cout << max << "\n";
    }
}
