#include <iostream>
#include <cstdlib>
#include <queue>
#include <chrono>

// Function that given an array of n elements, gets the k minimuns
int* K_Min(int* array, int n, int k){
   if (k>=n) return array; // If n is lower or equel than k, returns the array

   int* ret = new int[k];
   // Initialize the heap with the first k elements of the array
   std::priority_queue<int> p (array, array+k);

   // Loop through the rest of the elements
   for (int i=k; i<n; ++i){
      // If the top is higher than the current element, pop it and push the
      // the new element.
      if(array[i]<p.top()){
         p.pop();
         p.push(array[i]);
      }
   }

   // Copy the heap in an array of length k
   for (int i=0; !p.empty(); ++i){
      ret[i] = p.top();
      p.pop();
   }

   return ret;
}

// Main program
int main(int argc, char* argv[]){
   // Check passed arguments
   if (argc != 3){
      std::cerr << "Formato " << argv[0] << " <num_elem> <k_min>" << std::endl;
      return -1;
   }

   // Some initializations
   int n = atoi(argv[1]);
   int k = atoi(argv[2]);
   int * array = new int[n];
   int * k_min;
   srand(time(0));

   for (int i = 0; i < n; i++){
      array[i] = rand()%n;
   }

   // Calculating the execution time
   std::chrono::high_resolution_clock::time_point tantes, tdespues;
   std::chrono::duration<double> transcurrido;

   tantes = std::chrono::high_resolution_clock::now();
   k_min = K_Min(array, n, k);
   tdespues = std::chrono::high_resolution_clock::now();

   transcurrido = std::chrono::duration_cast<std::chrono::duration<double>>(tdespues - tantes);

   std::cout << "Size: " << n << ", Min Size: " << k << ", Time: " << transcurrido.count() << std::endl;
}
