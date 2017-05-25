#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// Numerical comparison using strings
bool comp(const std::string& lhs, const std::string& rhs){
   int n = lhs.length(), m = rhs.length();
   if (n==m) return lhs<rhs; // If the length is the same, string comparison
   else return n<m;  // The bigger the length, the bigger the number
}

int main(int argc, char* argv[]) {
   int n;
   std::cin >> n;

   std::vector<std::string> v(n);

   // Read data
   for (int i=0; i<n; ++i){
      std::cin >> v[i];
   }

   // Sort the data using comp()
   std::sort(v.begin(), v.end(), comp);

   // Print results
   for (auto i : v){
      std::cout << i << std::endl;
   }
}
