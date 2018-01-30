##########################################################################################
##  Project Euler #25: N-digit Fibonacci number                                         ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler025/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

from math import log, floor

fib_seq = [0, 1]

def fib(n):
    while n >= len(fib_seq):
        fib_seq.append(fib_seq[-1] + fib_seq[-2])
    return fib_seq[n]

phi = (1 + 5**0.5)/2
c = log(10, phi)

def a(n):
    if n == 1:
        return 1
    else:
        return floor((n-1)*c) + 2

T = int(input())

for i in range(T):
    N = int(input())

    candidate = a(N)

    if len(str(fib(candidate))) == N:
        print(candidate)
    else:
        print(candidate+1)
