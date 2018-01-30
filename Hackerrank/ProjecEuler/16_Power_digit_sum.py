##########################################################################################
##  Project Euler #16: Power digit sum                                                  ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler016/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

from math import pow

def sum_digits(n):
    s = 0
    while n:
        n, remainder = divmod(n, 10)
        s += remainder
    return s

T = int(input())

for i in range(T):
    N = int(input())

    print(sum_digits(2**N))
