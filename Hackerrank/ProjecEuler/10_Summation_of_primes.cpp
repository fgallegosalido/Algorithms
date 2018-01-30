//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #10: Summation of primes                                              //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem  //
//  Difficulty: Medium                                                                  //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

// Function that returns the primes number up to a top using the
// Eratosthenes sieve.
auto eratosthenes_sieve(unsigned long range){
   std::vector<unsigned long> sieve(range+1, 0); // All are not primes by default

   // Initialize 2 as prime
   sieve[2] = 2;
   // Mark all the odd numbers as primes
   for (unsigned long i=3; i<sieve.size(); i+=2){
      sieve[i] = i;
   }

   // Top to check primes
   unsigned long top = static_cast<unsigned long>(std::sqrt(range));
   // For every odd number up to the top:
   for (unsigned long i=3; i<=top; i+=2){
      // Mark all multiples of the number as not primes
      for (unsigned long j=i*3; j<sieve.size(); j += i*2){
         sieve[j] = 0;
      }
   }

   return sieve;
}

auto accumulative_prime_sums(unsigned long range){
    auto sums = std::move(eratosthenes_sieve(range));

    for (unsigned long i=1; i<=range; ++i){
        sums[i] += sums[i-1];
    }

    return sums;
}


int main() {
    auto sieve = std::move(accumulative_prime_sums(1000000));
    unsigned long T, N;
    std::cin >> T;

    for (unsigned long i=0; i<T; ++i){
        std::cin >> N;

        std::cout << sieve[N] << std::endl;
    }
}
