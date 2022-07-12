# -*- coding: utf-8 -*-
# 이동한 위치에서 상하좌우의 경우를 모두 고려하여 최소 값을 찾아야하기 때문에 bfs로 풀이
# (0,0)부터 (N,M)까지 모두 순회하는 것을 반복문의 조건으로 줌
# 방문했으면 visited를 True로 바꾸고 상하좌우 순서대로 "1"이 위치한 곳의 좌표를 큐에 append
# 참조하는 좌표가 (N,M)일 경우 min(ans, cnt)로 ans update
# 참조하는 좌표에서 상하좌우 모두 "0"인 경우 continue
#   => dfs는 시간 초과

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
maze = []
visited = []
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

for _ in range(N):
    maze.append(input())
    visited.append([False for _ in range(M)])

def bfs(q):
    global maze, visited, N, M

    while q:
        tmp = q.popleft()
        y, x, cnt = tmp[0], tmp[1], tmp[2]

        if y == N-1 and x == M-1: return cnt
        
        for idx in range(4):
            next_x, next_y = x+dx[idx], y+dy[idx]
            if  next_y >= 0 and next_y < N and next_x >= 0 and next_x < M:
                if visited[next_y][next_x]==False and maze[next_y][next_x]=="1":
                    visited[next_y][next_x] = True
                    q.append([next_y, next_x, cnt+1])
            else: continue

q = deque([[0,0,1]])
visited[0][0] = True
print(bfs(q))

# ans = (N*M)+1

# def check(y, x):
#     global maze, N, M
#     print("check" +str(N) + str(y))
#     if y >= 0 and y < N and x >= 0 and x < M: return maze[y][x]

# def dfs(y, x, cnt):
#     global maze, visited, ans, N, M

#     visited[y][x] = True
    
#     if y == N-1 and x == M-1:
#         ans = min(ans, cnt)
#         return True

#     for idx in range(4):
#         next_x, next_y = x+dx[idx], y+dy[idx]
#         if check(next_y, next_x) == "1" and visited[next_y][next_x]==False:
#             dfs(next_y, next_x, cnt+1)
#             visited[next_y][next_x] = False
# dfs(0, 0, 1)
# print(ans)