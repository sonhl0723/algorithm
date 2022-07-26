# -*- coding: utf-8 -*-
# 출발점과 도착점 사이의 거리에 따라 반복되는 규칙이 있는 문제
# 점 사이의 거리가 2이하일 경우 거리에 따라 작동 획수 설정
# 점 사이의 거리가 2초과일 경우 4개부터 2개씩 증가하며 작동 획수 반복

import sys

T = int(input())

for _ in range(T):
    x, y = map(int, sys.stdin.readline().split())
    dist = y-x

    if dist <= 2: ans = dist
    else:
        tmp = 2
        inc = 4

        while 1:
            if tmp+inc+2 <= dist:
                tmp += inc
                inc += 2
            else: break

        if tmp + inc//2 >= dist: ans = inc-1
        else: ans = inc

    print(ans)
            