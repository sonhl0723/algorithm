# -*- coding: utf-8 -*-
# 동생을 찾는 가장 빠른 시간을 구하는 것이기 때문에 너비 우선 탐색(bfs)로 문제를 해결
# 종료 조건: 현재의 위치가 0 미만일 경우 혹은 100,000 초과일 경우 stop,
#           현재의 위치가 동생의 위치와 일치하는 경우 min(ans, cnt)로 ans update
# 재귀 조건: 현재의 위치가 동생의 위치보다 작은 경우 x+1, 2*x 두 가지 경우를 cnt+1로 큐에 추가
#           현재의 위치가 동생의 위치보다 클 경우 x-1 한 가지 경우만 cnt+1로 큐에 추가


import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

q = deque([[N, 0]])
visited = [0 for _ in range(100001)]

def bfs():
    global M, q
    
    while q:
        top_ = q.popleft()
        x, cnt = top_[0], top_[1]

        if x == M: return cnt

        if x < 0 or x > 100000: continue

        if visited[x] == 0:
            visited[x] = 1
            if x == 0: q.append([x+1, cnt+1])
            else:
                q.append([x+1, cnt+1])
                q.append([x*2, cnt+1])
                q.append([x-1, cnt+1])

    return -1

print(bfs())