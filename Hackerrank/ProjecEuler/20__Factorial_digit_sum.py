##########################################################################################
##  Project Euler #20: Factorial digit sum                                              ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler020/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

from math import factorial

def sum_digits(n):
    s = 0
    while n:
        n, remainder = divmod(n, 10)
        s += remainder
    return s

T = int(input())

for i in range(T):
    N = int(input())

    print(sum_digits(factorial(N)))
