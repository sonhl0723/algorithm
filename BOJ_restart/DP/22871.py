# -*- coding: utf-8 -*-
# (j-i)*(1+abs(A_j-A_i))
# 각 위치마다 걸리는 최대값 중 최소값을 찾는 문제이다.

import sys

input = sys.stdin.readline

N = int(input())
_list = list(map(int, input().split()))
dp = [0]+[29999999999]*(N-1)
# for _ in range(N-1): dp.append(29999999999)

for i in range(1, N):
    for j in range(i):
        tmp = max((i-j)*(1+abs(_list[i]-_list[j])), dp[j])
        dp[i] = min(tmp, dp[i])

print(dp[-1])