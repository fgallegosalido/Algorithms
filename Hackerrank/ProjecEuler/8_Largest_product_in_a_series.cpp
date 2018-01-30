//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #8: Largest product in a series                                       //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main() {
    int T, N, K;
    std::string number;
    unsigned max, current;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N >> K;
        std::cin >> number;

        max = 0;
        auto first = number.begin(), last = number.begin()+K;

        while (last != number.end()){
            current = 1;
            for (auto it = first; it != last; ++it){
                current *= static_cast<unsigned>(*it - '0');
            }

            if (current > max) max = current;

            ++first; ++last;
        }

        std::cout << max << std::endl;
    }
}
