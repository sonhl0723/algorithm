# -*- coding: utf-8 -*-
# (j-i)*(1+abs(stones[i]-stones[j])) <= K 이 조건이 충족되어야함
# 

import sys

N, K = map(int, sys.stdin.readline().split())
stones = list(map(int, sys.stdin.readline().split()))

ans = [False for _ in range(N)]
ans[0] = True

for j in range(1, N):
    for i in range(j):
        if ans[i] and (j-i)*(1+abs(stones[i]-stones[j])) <= K:
            ans[j] = True
            break

if ans[N-1]: print("YES")
else: print("NO")