//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #18: Maximum path sum I                                               //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler018/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <algorithm>

int triangle_sum(const std::vector<std::vector<int>>& t, int depth, int offset){
    if (depth == t.size()-1)
        return t[depth][offset];
    else
        return t[depth][offset] +
                    std::max(triangle_sum(t, depth+1, offset),
                             triangle_sum(t, depth+1, offset+1));
}

int main() {
    int T, N, sum;
    std::vector<std::vector<int>> triangle;

    std::cin >> T;

    for (int k=0; k<T; ++k){
        std::cin >> N;

        for (int i=0; i<N; ++i){
            triangle.emplace_back(std::vector<int>(i+1));

            for (int j=0; j<=i; ++j){
                std::cin >> triangle[i][j];
            }
        }

        std::cout << triangle_sum(triangle, 0, 0) << std::endl;
        triangle.clear();
    }
}
