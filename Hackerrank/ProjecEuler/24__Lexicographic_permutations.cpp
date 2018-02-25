//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #24: Lexicographic permutations                                       //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler024/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
static constexpr const char* word = "abcdefghijklm";

void nth_permutation_aux(long n, long lo, long hi, std::string& buff, std::string& ret){
    if (buff.size() == 1)
        ret += buff;
    else{
        long range_size = (hi-lo)/buff.size(), index = n/range_size;
        ret += buff[index];
        buff.erase(index, 1);
        nth_permutation_aux(n-index*range_size, index*range_size, (index+1)*range_size, buff, ret);
    }
}

std::string nth_permutation(long n){
    std::string ret(""), buff(word);
    nth_permutation_aux(n-1, 0, 6227020800, buff, ret);
    return ret;
}

int main() {
    int T;
    long N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << nth_permutation(N) << std::endl;
    }
}
