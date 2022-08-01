# -*- coding: utf-8 -*-

import sys

N = int(input())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

A.sort(reverse=True)
B.sort()
ans = 0

for idx in range(N): ans += A[idx]*B[idx]

print(ans)