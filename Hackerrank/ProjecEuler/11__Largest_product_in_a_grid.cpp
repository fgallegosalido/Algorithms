//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #11: Largest product in a grid                                        //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    int grid[20][20];
    int biggest = 0;

    for (auto it = std::begin(grid); it != std::end(grid); ++it)
        for (auto itt = std::begin(*it); itt != std::end(*it); ++itt)
            std::cin >> *itt;

    for (auto i=0; i<17; ++i){
        for (auto j=0; j<17; ++j){
            biggest = std::max(biggest,
                       std::max(grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3],
                        std::max(grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j],
                         std::max(grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3],
                                   grid[i][j+3]*grid[i+1][j+2]*grid[i+2][j+1]*grid[i+3][j]
                      ))));
        }
    }

    for (auto i=17; i<20; ++i){
        for (auto j=0; j<17; ++j){
            biggest = std::max(biggest,
                       std::max(grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3],
                                 grid[j][i]*grid[j+1][i]*grid[j+2][i]*grid[j+3][i]
                      ));
        }
    }

    std::cout << biggest;
}
