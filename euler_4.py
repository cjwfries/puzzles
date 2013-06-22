import math

"""
06/21/13

Project Euler #4 Largest Palindrome Product
    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
    Find the largest palindrome made from the product of two 3-digit numbers.

Algorithm
    Fairly straight-forward. One optimization was to let b end at the current a to avoid repeat calculations (halves the total number of calculations). For example, we don't want to calculate 100*200 and 200*100.

    Further math-based optimizations (not included in code, from solution):
    We know that the minimum palindrome for the case of 3 digits would be 111111 = 143*777, and the maximum product of two 3 digit numbers is 999*999 = 998001. Therefore, we know that the output has to be 6 digits.
    n = 100000x + 10000y + 1000z + 100z + 10y + 1x
      = 100001x + 10010y + 1100z
      = 11(9041x + 910y + 100z)
    Therefore for n to be a palindrome, a or b must be divisible by 11.
"""

def halvesStr(s):
    return (s[0:len(s)//2], s[math.ceil(len(s)//2):len(s)])

def isPal(tup):
    if tup[0] == tup[1][::-1]: # reverse second half
        return True
    else:
        return False

def palProd(digits):
    # ex. 3 digits: 100 - 999
    minimum = pow(10, digits-1)
    maximum = pow(10, digits) - 1
    ret = -1
    for a in range(maximum, minimum, -1):
        for b in range(a, minimum, -1):
            if isPal(halvesStr(str(a*b))):
                if a*b > ret:
                    ret = a*b
    return ret
