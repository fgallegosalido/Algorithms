//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #7: 10001st prime                                                     //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

// Function that returns the primes number up to a top using the
// Eratosthenes sieve.
std::deque<unsigned long> eratosthenes_sieve(const unsigned long &range){
   std::vector<bool> mask(range+1, true); // Vector to mark primes as true
   std::deque<unsigned long> primes;       // List with the primes

   // Initialize 1 as not prime and 2 as prime
   mask[0] = false;
   mask[1] = true;

   // Mark all the even numbers as not prime and the odd ones as primes
   for (int i=2; i<range; i+=2){
      mask[i+1] = false;
   }

   // Top to check primes
   unsigned long top = static_cast<unsigned long>(std::sqrt(range));

   // For every odd number up to the top:
   for (unsigned long i=2; i<top; i+=2){
      // Mark all multiples of the number as not primes
      for (unsigned long j=i*3+2; j<range; j += (i+1)*2){
         mask[j] = false;
      }
   }

   // Push in the list all the primes
   for (unsigned long i=0; i<range; ++i){
      if (mask[i]) primes.push_back(i+1);
   }

   return primes;
}


int main() {
    auto primes = eratosthenes_sieve(104730);
    int T;
    unsigned long N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << primes[N-1] << std::endl;
    }
}
