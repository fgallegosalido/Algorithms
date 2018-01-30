##########################################################################################
##  Project Euler #13: Large sum                                                        ##
##                                                                                      ##
##  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler013/problem  ##
##  Difficulty: Easy                                                                    ##
##  Language: Python 3                                                                  ##
##########################################################################################

T = int(input())
list = []

for i in range(T):
    list.append(int(input()))

result = sum(list)

while result > 9999999999:
    result = result // 10

print(result)
