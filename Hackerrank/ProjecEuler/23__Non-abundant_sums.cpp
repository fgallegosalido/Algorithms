//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #23: Non-abundant sums                                                //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler023/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <utility>

bool is_abundant(int n){
    if (n < 12)
        return false;

    int sum = 1, top = (n%2==0)?n/2:((n%3==0)?n/3:n/5);

    for (int i=2; i<=top; ++i){
          if (n%i == 0) sum += i;
    }

    return sum > n;
}

auto generate_abundants(int top){
    std::vector<bool> ret(top+1, false);

    for (int i=12; i<=top; ++i)
        if (is_abundant(i))
            ret[i] = true;

    return ret;
}

bool is_sum_of_two_abundants(int n, const std::vector<bool>& v){
    if (n<24)
        return false;
    if (n>20161)
        return true;

    for (int i=12; i<=n/2; ++i){
        if (v[i] && v[n-i])
            return true;
    }

    return false;
}

int main() {
    auto sieve = std::move(generate_abundants(20160));
    int T, N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        std::cout << (is_sum_of_two_abundants(N, sieve) ? "YES" : "NO") << std::endl;
    }
}
