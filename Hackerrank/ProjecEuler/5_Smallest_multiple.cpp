//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #5: Smallest Multiple                                                 //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler005/problem  //
//  Difficulty: Medium                                                                  //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

unsigned long gcd (unsigned long n, unsigned long m){
    if (m==0) return n;
    else return gcd(m, n%m);
}

unsigned long lcm (unsigned long n, unsigned long m){
    return (n/gcd(n, m))*m;
}

unsigned long multiple_lcm (unsigned long n){
    if (n<3) return n;
    else return lcm(n, multiple_lcm(n-1));
}


int main() {
    int T;
    unsigned long N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << multiple_lcm(N) << std::endl;
    }
}
