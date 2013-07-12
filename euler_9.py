"""
06/52/13

Project Euler #9 Special Pythagorean triplet
    A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
    a^2 + b^2 = c^2
    For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.
    
Algorithm
    Use Euclid's formula, where a = m^2 - n^2; b = 2mn; c = m^2 + n^2
"""

def pythagTrip(total):
    for n in range(1, total):
        for m in range(n+1, total):
            if 2*m*m+2*m*n == total:
                return (m*m-n*n) * (2*m*n) * (m*m+n*n)
