import sys
from typing import List, Tuple

def sieve_of_eratosthenes(n: int) -> List[int]:
    is_prime = [False, False] + [True] * (n - 1)
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return primes

def goldbach(n: int, primes: List[int]) -> Tuple[int, int]:
    idx = 0
    while primes[idx] <= n // 2:
        p = primes[idx]
        if is_prime[n - p]: return (p, n - p)
        idx += 1
    return None

primes = sieve_of_eratosthenes(1000000)
is_prime = [False] * 1000001
for p in primes:
    is_prime[p] = True

for line in sys.stdin:
    n = int(line.strip())
    if n == 0:
        break
    result = goldbach(n, primes)
    if result is None:
        print("Goldbach's conjecture is wrong.")
    else:
        a, b = result
        print(f"{n} = {a} + {b}")