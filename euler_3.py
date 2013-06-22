from math import floor, sqrt

"""
06/21/13

Project Euler #3 Largest Prime Factor
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143 ?

Algorithm
    We only need to check up to sqrt(n) to see if n is prime-
    Let m = sqrt(n); if n is not prime, n = a*b
    There are 3 possible cases-
    1. a > m ; b < m
    2. a = m ; b = m
    3. a < m ; b > m
    No matter what, min(a,b) <= m
    Therefore, if we search until m, we will find at least one factor of n, showing that n is not prime.

    The smallest factor of a number is prime.
    Proof: If the smallest factor x is not prime, then there exists a and b such that x = a*b.
    a and b are smaller than x.
    Then x is not the smallest factor. Proof by contradiction.

    Example n = 12:
    1. return max(2, largestPrime(6))
    2. return max(2, largestPrime(3))
    3. return 3
"""


def largestPrime(n):
    for i in range(2, floor(sqrt(n))):
        if n % i == 0:
            return max(i, largestPrime(floor(n/i)))
    return n # if n isn't divisible, it is prime
        
