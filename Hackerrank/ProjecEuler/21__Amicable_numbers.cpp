//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #21: Amicable numbers                                                 //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler021/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

std::array<int, 26> amicables = {
    220, 284, 1184, 1210, 2620, 2924, 5020, 5564, 6232, 6368, 10744, 10856, 12285, 14595,
    17296, 18416, 63020, 66928, 66992, 67095, 69615, 71145, 76084, 79750, 87633, 88730
};

int main() {
    int T, N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << std::accumulate(amicables.begin(),
                        std::upper_bound(amicables.begin(), amicables.end(), N-1), 0)
                  << std::endl;
    }
}
