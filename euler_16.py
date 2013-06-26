import math

"""
06/52/13

Project Euler #16 Power Digit Sum
    2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
    What is the sum of the digits of the number 2^1000?
    
Algorithm
    Convert number to string, add up each digit
"""

def sumDigits(s):
    ret = 0
    for i in range(len(s)):
        ret += int(s[i])
    return ret

def main(x, power):
    num = pow(x, power)
    return sumDigits(str(num))
