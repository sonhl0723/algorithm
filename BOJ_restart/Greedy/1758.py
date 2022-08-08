# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

N = int(input())
tip = []

for _ in range(N): tip.append(int(input()))

tip.sort(reverse=True)
ans = 0

for idx in range(1, N+1):
    tmp = tip[idx-1]-(idx-1)
    if tmp > 0: ans += tmp

print(ans)