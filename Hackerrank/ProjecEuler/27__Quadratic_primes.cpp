//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #27: Quadratic primes                                                 //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler027/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

bool is_prime (int n){
    if (n<2)
        return false;
    if (n==2 || n==3)
        return true;

    bool is_prime = n%2 != 0 && n%3 != 0;
    int top = static_cast<int>(sqrt(n)+1);

    for (int i=3; i<top && is_prime; i+=6)
        is_prime = (n%(i+2) != 0) && (n%(i+4) != 0);

    return is_prime;
}

auto eratosthenes_sieve(int range){
    std::vector<bool> mask(range+1, true);
    std::vector<int> primes;

    mask[0] = false;

    for (int i=2; i<range; i+=2){
        mask[i+1] = false;
    }

    int top = static_cast<int>(std::sqrt(range));

    for (int i=2; i<top; i+=2){
        for (int j=i*3+2; j<range; j += (i+1)*2){
            mask[j] = false;
        }
    }

    for (int i=0; i<range; ++i){
        if (mask[i]) primes.push_back(i+1);
    }

    return primes;
}

auto find_quadratic(int n){
    int a, b, max = 0;
    auto sieve = eratosthenes_sieve(n);

    for (auto p : sieve){
        for (int i=-n; i<=n; i += 2){
            int j = 0, count = 0;

            while (is_prime(j*j + i*j + p)){
                ++count;
                ++j;
            }

            if (count > max){
                max = count;
                a = i;
                b = p;
            }
        }
    }

    return std::make_pair(a, b);
}

int main() {
    std::pair<int, int> coeffs;
    int N; std::cin >> N;

    if (N%2 == 0)
        coeffs = std::move(find_quadratic(N-1));
    else
        coeffs = std::move(find_quadratic(N));

    std::cout << coeffs.first << " " << coeffs.second << std::endl;
}
