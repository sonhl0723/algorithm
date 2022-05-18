# -*- coding: utf-8 -*-

import sys

N = int(sys.stdin.readline().split()[0])
arr = []
answer = 0

for _ in range(N): arr.append(int(sys.stdin.readline().split()[0]))

arr.sort()

for idx in range(N):
    tmp = ((N)-idx)*arr[idx]
    answer = max(answer, tmp)

print(answer)