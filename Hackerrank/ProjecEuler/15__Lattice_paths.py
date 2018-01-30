##########################################################################################
##  Project Euler #15: Lattice paths                                                    ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler015/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

from math import factorial

T = int(input())

for i in range(T):
    N, M = [int(n) for n in input().split()]

    print((factorial(N+M)//(factorial(N)*factorial(M)))%1000000007)
