##########################################################################################
##  Project Euler #26: Reciprocal cycles                                                ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler026/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

from math import sqrt

def primes_sieve(n):
    a = [True] * (n+1)
    a[0] = a[1] = False

    for i in [2*k for k in range(2, n // 2)]:
        a[i] = False

    top = int(sqrt(n)) + 2

    for i in [2*k + 1 for k in range(1, top // 2)]:
        for j in [i*k for k in range(2, n // i + 1)]:
            a[j] = False
    return a

def is_reptend(n):
    if n < 7:
        return False

    l = []
    for i in range(1, n):
        l.append(pow(10, i, n))

    if len(set(l)) == n-1:
        return True
    else:
        return False

def reptend_sieve(n):
    a = primes_sieve(n)

    for i in range(len(a)):
        if a[i]:
            if not is_reptend(i):
                a[i] = False
    return a

sieve = reptend_sieve(10000)
solution = [1, 1, 3, 3, 3, 3]
current = 3

for i in range(7, len(sieve)):
    if sieve[i]:
        current = i
    solution.append(current)

T = int(input())

for _ in range(T):
    N = int(input())
    print(solution[N-2])
