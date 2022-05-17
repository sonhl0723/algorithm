# -*- coding: utf-8 -*-
# 입력받는 A, B 배열은 정렬이 되어 있기 때문에 각 배열마다 포인터를 두고 투포인터로 문제를 해결한다.
# 두 포인터 중 하나라도 끝까지 간다면 또 다른 포인터의 배열은 포인터의 위치부터 끝까지 바로 정답 배열에 붙인다.

import sys

N, M = map(int, sys.stdin.readline().split())
A = []
B = []
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

a_idx = 0
b_idx = 0

while a_idx != N and b_idx != M:
    if A[a_idx] == B[b_idx]:
        print(A[a_idx], end=' ')
        a_idx += 1
    elif A[a_idx] > B[b_idx]:
        print(B[b_idx], end=' ')
        b_idx += 1
    else:
        print(A[a_idx], end=' ')
        a_idx += 1

if a_idx == N:
    while b_idx != M:
        if b_idx == M-1: print(B[b_idx])
        else: print(B[b_idx], end=' ')
        b_idx += 1
else:
    while a_idx != N:
        if a_idx == N-1: print(A[a_idx])
        else: print(A[a_idx], end=' ')
        a_idx += 1