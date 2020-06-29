from math import sqrt
def segmentedSieve(L,R):
    limit = int(sqrt(R))
    mark = [False for i in range(limit+1)]
    primes = []
    for i in range(2,limit+1):
        if not mark[i]:
            primes.append(i)
            for j in range(i*i,limit+1,i):
                mark[j] = True
    isPrime = [True for i in range(R-L+1)]
    for i in primes:
        for j in range(max(i * i, (L + i - 1) // i * i),R+1,i):
            isPrime[j-L] = 0
    if L == 1 and isPrime[0]:
        isPrime[0] = False
    return isPrime

a = int(input())
b = int(input())
tot = 0
for b in segmentedSieve(a,b-1):
    if b:
        tot += 1
print(tot)
