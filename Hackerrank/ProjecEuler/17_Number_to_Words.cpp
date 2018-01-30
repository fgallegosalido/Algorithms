//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #17: Number to Words                                                  //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler017/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

std::string get_word(unsigned long n){
    switch(n){
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";
        case 20:
            return "Twenty";
        case 30:
            return "Thirty";
        case 40:
            return "Forty";
        case 50:
            return "Fifty";
        case 60:
            return "Sixty";
        case 70:
            return "Seventy";
        case 80:
            return "Eighty";
        case 90:
            return "Ninety";
        default:
            return "";
    }
}

std::string two_digits_word(unsigned long n){
    if (n<20)
        return get_word(n);
    else{
        if (n%10 == 0)
            return get_word(n-n%10);
        else
            return get_word(n-n%10)+" "+get_word(n%10);
    }
}

std::string three_digits_word(unsigned long n){
    if (n<100)
        return two_digits_word(n);
    else{
        if (n%100 == 0)
            return get_word(n/100)+" Hundred";
        else
            return get_word(n/100)+" Hundred "+two_digits_word(n%100);
    }
}

int main() {
    int T; std::cin >> T;
    unsigned long N;

    for (int i=0; i<T; ++i){
        std::cin >> N;

        if (N==0){
            std::cout << "Zero" << std::endl;
        }
        else if (N==1000000000000){
            std::cout << "One Trillion" << std::endl;
        }
        else{
            if (N>=1000000000){
                std::cout << three_digits_word(N/1000000000)+" Billion";
                if (N%1000000000 != 0)
                    std::cout << " ";

                N %= 1000000000;
            }

            if (N>=1000000){
                std::cout << three_digits_word(N/1000000)+" Million";
                if (N%1000000 != 0)
                    std::cout << " ";

                N %= 1000000;
            }

            if (N>=1000){
                std::cout << three_digits_word(N/1000)+" Thousand";
                if (N%1000 != 0)
                    std::cout << " ";

                N %= 1000;
            }

            if (N>0)
                std::cout << three_digits_word(N);

            std::cout << std::endl;
        }
    }
}
