# -*- coding: utf-8 -*-

import sys

A, B, C, M = map(int, sys.stdin.readline().split())
tired = 0
ans = 0

for _ in range(24):
    if tired+A <= M:
        tired += A
        ans += B
    else: tired -= C

    if tired < 0: tired = 0

print(ans)