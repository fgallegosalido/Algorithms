##########################################################################################
##  Project Euler #28: Number spiral diagonals                                          ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler028/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

def f(n):
    return 1 + 10*n**2 + ((16*n**3 + 26*n)//3)

T = int(input())

for _ in range(T):
    N = int(input())

    print(f((N-1)//2)%1000000007)
