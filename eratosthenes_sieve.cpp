#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <chrono>

// Function that checks if the number passed is prime
bool IsPrime (const unsigned long &n){
   if (n==2 || n==3) return true;

   bool is_prime = n%2 != 0 && n%3 != 0;
   unsigned long top = (unsigned long) sqrt(n)+1;

   for (unsigned long i=3; i<top && is_prime; i+=6){
      is_prime = (n%(i+2) != 0) && (n%(i+4) != 0);
   }

   return is_prime;
}

// Function that returns the primes number up to a top using the
// Eratosthenes sieve.
std::list<unsigned long> EratosthenesSieve(const unsigned long &range){
   std::vector<bool> mask(range+1, true); // Vector to mark primes as true
   std::list<unsigned long> primes;       // List with the primes

   // Initialize 1 as not prime and 2 as prime
   mask[0] = false;
   mask[1] = true;

   // Mark all the even numbers as not prime and the odd ones as primes
   for (int i=2; i<range; i+=2){
      mask[i] = true;
      mask[i+1] = false;
   }

   // Top to check primes
   unsigned long top = (unsigned long) sqrt(range);

   // For every odd number up to the top:
   for (unsigned long i=2; i<top; i+=2){
      // If the number is prime:
      if (IsPrime(i+1)){
         // Mark all multiples of the number as not primes
         for (unsigned long j=i*3+2; j<range; j += (i+1)*2){
            mask[j] = false;
         }
      }
   }

   // Push in the list all the primes
   for (unsigned long i=0; i<range; ++i){
      if (mask[i]) primes.push_back(i+1);
   }

   return primes;
}

int main (int argc, char* argv[]){
   // Check passed arguments
   if (argc != 2){
      std::cerr << "Formato " << argv[0] << "<top>" << std::endl;
      return -1;
   }

   // Some initializatins
   unsigned long n = strtoul(argv[1], NULL, 0);
   std::list<unsigned long> primes;

   // Check execution time
   std::chrono::high_resolution_clock::time_point tantes, tdespues;
   std::chrono::duration<double> transcurrido;

   tantes = std::chrono::high_resolution_clock::now();
   primes = EratosthenesSieve(n);
   tdespues = std::chrono::high_resolution_clock::now();

   transcurrido = std::chrono::duration_cast<std::chrono::duration<double>>(tdespues - tantes);
   std::cout << transcurrido.count() << std::endl;

   // If the top is lower than 1000, print all the primes.
   if (n<=1000){
      std::cout << "Primes up to " << n << ":\n";

      for (auto i : primes){
         std::cout << i << ", ";
      }
      std::cout << "\b\b " << std::endl;
   }
   // Print also the number of primes
   std::cout << "Number of primes up to " << n << ": " << primes.size() << std::endl;
}
