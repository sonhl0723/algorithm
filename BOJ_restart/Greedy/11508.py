# -*- coding: utf-8 -*-

import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
cost = []

for _ in range(N): cost.append(int(input()))

cost.sort()
cost = deque(cost)
idx, ans, flag = 0, 0, 0

while cost:
    tmp = cost.pop()
    if flag < 2:
        ans += tmp
        flag += 1
    else: flag = 0

print(ans)