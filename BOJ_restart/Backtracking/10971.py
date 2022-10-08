# -*- coding: utf-8 -*-
# 외판원 순회
# 깊이 우선 탐색

import sys

input = sys.stdin.readline

N = int(input())

_map = []

for _ in range(N): _map.append(list(map(int, input().split())))
ans = N*900000000

def dfs(start, cur, rm, cnt, visited):
    global _map, ans

    if cnt >= ans: return
    
    if start == cur and rm == 0:
        ans = min(ans, cnt)
        return
    
    for j in range(N):
        if j != cur and visited[j] == False and _map[cur][j] != 0:
                visited[j] = True
                dfs(start, j, rm-1, cnt+_map[cur][j], visited)
                visited[j] = False
        

for i in range(N):
    visited = [False]*N
    dfs(i, i, N, 0, visited)

print(ans)