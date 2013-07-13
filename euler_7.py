"""
06/22/13

Project Euler #7 10001st prime
    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
    What is the 10 001st prime number?
    
Algorithm
    Not very elegant- it's based on guessing the upper bound of the 10001st prime, which I guessed to be 300000.
    I thought of making this function more flexible and allow us to find primes past the 10001st prime by constantly guessing a bigger number based on the number of primes we are able to generate by the first guess, however it wouldn't be very practical, seeing how long it took the computer to find 10001 primes.
    After this, I used the Sieve of Eratosthenes.
"""

def getPrimes(num):
    ret = []
    sieve = []
    numPrimes = 0
    maxSearch = 300000
    for i in range(2, maxSearch):
        sieve.append(i)
    for i in range(len(sieve)):
        if sieve[i] != -1:
            numPrimes += 1
            if numPrimes == num:
                return sieve[i]
            incr = 2
            x = incr*sieve[i]
            while(x < maxSearch):
                sieve[x-2] = -1
                incr += 1
                x = incr*sieve[i]
    for i in range(len(sieve)):
        if sieve[i] != -1:
            ret.append(sieve[i])
    return -1
        
