# -*- coding: utf-8 -*-
# 모든 경우의 수를 돌며 최대값을 구하는 문제이므로 dfs를 활용
# 가장 왼쪽의 계란부터 시작하여 오른쪽으로 한 칸씩 이동
# 

import sys

N = int(input())
eggs = [] # eggs[idx][0]=>내구도 / eggs[idx][1]=>무게
for _ in range(N): eggs.append(list(map(int, sys.stdin.readline().split())))

ans = -1

def dfs(eggs, idx):
    global N, ans

    if idx == N:
        broken = 0
        for i in range(N):
            if eggs[i][0] <= 0: broken += 1
        ans = max(ans, broken)
        return
    elif eggs[idx][0] <= 0:
        dfs(eggs, idx+1)
        return
    
    flag = False
    for right in range(N):
        if ans == N: return
        if eggs[right][0] <= 0 or right == idx: continue
        else:
            eggs[idx][0] -= eggs[right][1]
            eggs[right][0] -= eggs[idx][1]

            flag = True
            dfs(eggs, idx+1)

            eggs[idx][0] += eggs[right][1]
            eggs[right][0] += eggs[idx][1]

    if not flag: dfs(eggs, N)

dfs(eggs, 0)

print(ans)