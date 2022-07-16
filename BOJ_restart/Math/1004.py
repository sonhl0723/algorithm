# -*- coding: utf-8 -*-
# 출발점에서 최소한의 원을 거쳐 도착점에 도달할 때, 거쳐야 하는 원이 개수를 출력
# 출발점과 도착점 각각 내접, 외접, 안에 있는 경우를 확인
#   고려하는 원 안에 출발점과 도착점이 같이 존재한다면 진입/이탈을 하지 않기 때문에 제외시켜줘야함

import sys
import math

T = int(input())

for _ in range(T):

    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    N = int(input())
    ans = 0

    for _ in range(N):
        cx, cy, r = map(int, sys.stdin.readline().split())

        d1 = math.sqrt(abs(x1-cx)**2 + abs(y1-cy)**2)
        d2 = math.sqrt(abs(x2-cx)**2 + abs(y2-cy)**2)

        if d1 < r or d2 < r: ans += 1
        if d1 < r and d2 < r: ans -= 1

    print(ans)