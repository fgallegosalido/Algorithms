//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #4: Largest palidrome product                                         //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem  //
//  Difficulty: Medium                                                                  //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

bool hasThreeDigits (int n){
    return n>=100 && n<1000;
}

int previousPalindrome (int n){
    if ((n/100)%10 != 0) return n-1100;
    else if ((n/10)%10 != 0) return n-110;
    else return n-11;
}

int biggestPalindromeLowerThan (int n){
    int ret = (n/1000)*1000 + ((n/1000)%10)*100 + ((n/10000)%10)*10 + (n/100000)%10;
    return (n<=ret) ? previousPalindrome(ret) : ret;
}

bool isProductOfThreeDigitsFactors (int n){
    bool cond = false;

    for (int i=110; i<1000 && !cond; i+=11){
        if (n%i == 0)
            cond = hasThreeDigits(n/i);
    }

    return cond;
}

int finalPalindrome (int n){
    n = biggestPalindromeLowerThan(n);

    while (!isProductOfThreeDigitsFactors(n)){
        n = previousPalindrome(n);
    }

    return n;
}

int main() {
    int T, N;
    std::cin >> T;

    for (int i=0; i<T; ++i){
        std::cin >> N;
        std::cout << finalPalindrome(N) << std::endl;
    }
}
