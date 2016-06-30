#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cmath>

bool IsPrime2 (unsigned long &n){
   bool is_prime = n != 2;
   unsigned long top = (unsigned long) sqrt(n)+1;

   for (unsigned long i=3; i<top && is_prime; i+=2){
      is_prime = n%i != 0;
   }

   return is_prime;
}

// Function that given a natural number bigger than 1, check if it's prime.
bool IsPrime (unsigned long &n){
   // Get rid of base cases
   if (n==2 || n==3) return true;

   // Initialize the boolean to a intuitive correct value
   bool is_prime = n%2 != 0 && n%3 != 0;
   unsigned long top = (unsigned long) sqrt(n)+1;

   // This loop only does only sqrt(n)/6 iterations, but many less comparisons
   // (2 comparisons every 6 iterations), which reduces the execution time a lot
   for (unsigned long i=3; i<top && is_prime; i+=6){
      is_prime = (n%(i+2) != 0) && (n%(i+4) != 0);
   }

   return is_prime;
}

// Main program
int main (int argc, char* argv[]){
   // Check passed arguments
   if (argc != 2){
      std::cerr << "Formato " << argv[0] << "<num>" << std::endl;
      return -1;
   }

   // Some initializatins
   unsigned long n = strtoul(argv[1], NULL, 0);
   bool is_prime;

   // Check execution time
   std::chrono::high_resolution_clock::time_point tantes, tdespues;
   std::chrono::duration<double> transcurrido;

   tantes = std::chrono::high_resolution_clock::now();
   is_prime = IsPrime2(n);
   tdespues = std::chrono::high_resolution_clock::now();

   transcurrido = std::chrono::duration_cast<std::chrono::duration<double>>(tdespues - tantes);
   std::cout << transcurrido.count() << std::endl;

   // Print result
   if (is_prime){
      std::cout << "Prime" << std::endl;
   }
   else {
     std::cout << "Not prime" << std::endl;
   }
}
