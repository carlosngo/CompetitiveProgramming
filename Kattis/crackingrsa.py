import math
t = int(input())
primes = []
MAX_N = 1000
sieve = [False] * MAX_N
for i in range(2, MAX_N):
    if sieve[i] == False:
        primes.append(i)
        for j in range(i * i, MAX_N, i):
            sieve[j] = True
for i in range(t):
    s = input().split(' ')
    n = int(s[0])
    e = int(s[1])
    totient = 2
    for j in range(len(primes)):
        p = primes[j]
        if p > math.sqrt(n):
            break
        if n % p == 0:
            q = n // p
            totient = (p - 1) * (q - 1)
    for d in range(2, totient):
        if (d * e - 1) % totient == 0:
            print(d)
            break