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
            for j in range(i+1, len(sieve)):
                if sieve[j] != -1 and sieve[j] % sieve[i] == 0:
                    sieve[j] = -1
    for i in range(len(sieve)):
        if sieve[i] != -1:
            ret.append(sieve[i])
    return -1
        
