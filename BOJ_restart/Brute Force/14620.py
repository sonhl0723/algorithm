# -*- coding: utf-8 -*-
# 정원의 크기가 6*6 ~ 10*10이므로 모든 경우의 수를 다 따져도 제한 시간인 2분을 충족가능 -> 브루트포스
# 상하좌우의 cost를 계산해야하기 때문에 시작과 끝을 1,1 / N-1,N-1로 축소 => 모든 중간값에 대한 상하좌우 cost를 계산하여 정원 초기화

import sys

def dfs(start, cnt, cost):
    global visited, ans, dx, dy, N, sum_map

    if cnt == 3: ans = min(ans, cost)
    else:
        for y in range(start, N-1):
            for x in range(1, N-1):
                flag = True
                for idx in range(5):
                    if visited[y+dy[idx]][x+dx[idx]]:
                        flag = False
                        break
                if flag:
                    for idx in range(5): visited[y+dy[idx]][x+dx[idx]] = True

                    dfs(start, cnt+1, cost+sum_map[y][x])

                    for idx in range(5): visited[y+dy[idx]][x+dx[idx]] = False

_map = []
sum_map = []
visited = []
ans = 3001

N = int(input())
for _ in range(N):
    _map.append(list(map(int, sys.stdin.readline().split())))
    sum_map.append([0 for _ in range(N)])
    visited.append([False for _ in range(N)])

dx = [0, -1, 0, 1, 0]
dy = [0, 0, -1, 0, 1]

for y in range(1, N-1):
    for x in range(1, N-1):
        tmp = 0
        for idx in range(5): tmp += _map[y+dy[idx]][x+dx[idx]]
        sum_map[y][x] = tmp

_map = []

dfs(1, 0, 0)

print(ans)