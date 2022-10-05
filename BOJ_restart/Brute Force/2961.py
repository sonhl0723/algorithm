# -*- coding: utf-8 -*-
# itertools.combinations -> 순서를 고려하지 않고, 중복없이
# itertools.permutations -> 순서를 고려하고, 중복없이

import sys
from itertools import combinations
from functools import reduce

input = sys.stdin.readline

N = int(input())
a, b = [], []

for _ in range(N):
    tmp_a, tmp_b = input().split()
    a.append(tmp_a)
    b.append(tmp_b)

ans = 999999999

for i in range(1, N+1):
    com_a, com_b = list(combinations(a, i)), list(combinations(b, i))

    for tmp_a, tmp_b in zip(com_a, com_b):
        mul_a = reduce(lambda x, y: int(x) * int(y), tmp_a)
        sum_b = 0
        for elem in tmp_b: sum_b += int(elem)
        
        ans = min(ans, abs(int(mul_a)-sum_b))

print(ans)
