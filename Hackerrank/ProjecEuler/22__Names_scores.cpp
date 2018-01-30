//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #22: Names scores                                                     //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler022/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

int main() {
    int N, Q, score;
    std::string query;
    std::cin >> N;
    std::vector<std::string> names(N);

    for (int i=0; i<N; ++i){
        std::cin >> names[i];
    }
    std::sort(names.begin(), names.end());

    std::cin >> Q;

    for (int i=0; i<Q; ++i){
        std::cin >> query;

        std::cout << std::distance(names.begin(), std::find(names.begin(), names.end(), query)+1) *
                     std::accumulate(query.begin(), query.end(), 0, [](int lhs, char rhs){
                         return lhs+static_cast<int>(rhs-64);
                     })
                   << std::endl;
    }
}
