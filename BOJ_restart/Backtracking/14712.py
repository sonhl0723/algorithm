# -*- coding: utf-8 -*-
# 2x2 칸이 채워지지 않는 모든 경우의 수를 찾기 위해 깊이 우선 탐색(dfs)로 풀이
# 0,0부터 오른쪽, 밑으로 순차적으로 접근하기 때문에 왼쪽 상단에서의 2x2만을 확인
# 종료 조건: y == N일 경우 종료
# 넴모를 놓은 경우와 놓지 않은 경우 2가지 상황에서의 dfs 재귀 => Python3 시간 초과, Pypy3 정답
# *** 아무것도 올려놓지 않은 경우도 정답으로 간주하기 때문에 초기 ans를 1로 설정
# **** Python3로 시간 초과를 해결한 풀이는 찾을 수 없었다...

import sys

N, M = map(int, sys.stdin.readline().split())
map_ = []
for _ in range(N):
    map_.append([0 for _ in range(M)])

ans = 1

def check(y, x, map_):
    if map_[y-1][x] + map_[y][x-1] + map_[y-1][x-1] == 3: return False
    else: return True

def dfs(y, x, map_):
    global N, M, ans
    
    if y == N: return

    if x+1 < M:
        dy = y
        dx = x+1
    else:
        dy = y+1
        dx = 0

    if y==0 or x==0 or check(y, x, map_):
        ans += 1
        map_[y][x] = 1
        dfs(dy, dx, map_)
        map_[y][x] = 0
    dfs(dy, dx, map_)

dfs(0, 0, map_)

print(ans)