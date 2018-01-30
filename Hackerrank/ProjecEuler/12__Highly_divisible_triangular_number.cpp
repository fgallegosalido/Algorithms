//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #12: Highly divisible triangular number                               //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

constexpr unsigned sum_up_to(unsigned n){
    return n + (n*(n-1))/2;
}

unsigned divisors_of(unsigned n){
    if (n==1) return 1;
    unsigned count = 2, top = (n%2==0)?n/2:((n%3==0)?n/3:n/5);

    for (unsigned i=2; i<=top; ++i){
          if (n%i == 0) ++count;
    }

    return count;
}

int main() {
    unsigned T, N, n;
    std::vector<unsigned>  max_count(1, 1), divisors = {1, 2};
    std::cin >> T;

    for (unsigned i=0; i<T; ++i){
        std::cin >> N;

        auto found = std::upper_bound(max_count.begin(), max_count.end(), N);

        if (found != max_count.end()){
            std::cout << sum_up_to(std::distance(max_count.begin(), found) + 1) << "\n";
        }
        else{
            for (auto j = divisors.size(); N >= max_count.back(); ++j){
                divisors.push_back(divisors_of(j+1));

                if (j%2 == 0){
                    n = divisors[(j/2)-1]*divisors.back();
                }
                else{
                    n = divisors[j-1]*divisors[(j-1)/2];
                }

                if (n > max_count.back()){
                    max_count.push_back(n);
                }
                else{
                    max_count.push_back(max_count.back());
                }
            }

            std::cout << sum_up_to(max_count.size()) << "\n";
        }
    }
}
