# -*- coding: utf-8 -*-
# 두 개의 리스트가 주어졌을 때 S = A[0] × B[0] + ... + A[N-1] × B[N-1] 인 최소값 S를 출력
# 하나의 리스트는 오름차순 정렬, 다른 하나의 리스트는 내림차순 정렬을 한 다음 값을 구해주면 된다.

import sys

N = int(input())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

A.sort(reverse=True)
B.sort()
ans = 0

for idx in range(N): ans += A[idx]*B[idx]

print(ans)