"""
06/52/13

Project Euler #10 Summation of Primes
    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
    Find the sum of all the primes below two million.
    
Algorithm
    Use the Sieve of Eratosthenes to generate the primes. Then sum them up.
"""

def primesSum(ceiling):
    sieve = []
    pSum = 0
    for i in range(2, ceiling):
        sieve.append(i)
    for i in range(len(sieve)):
        if sieve[i] != -1:
            incr = 2
            x = incr*sieve[i]
            while(x < ceiling):
                sieve[x-2] = -1
                incr += 1
                x = incr*sieve[i]
    for i in range(len(sieve)):
        if sieve[i] != -1:
            pSum += sieve[i]
    return pSum
