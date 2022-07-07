# -*- coding: utf-8 -*-
# 모든 경우의 수를 돌며 최대값을 구하는 문제이므로 dfs를 활용
# 가장 왼쪽의 계란부터 시작하여 가장 오른쪽의 계란까지 이동
# 왼쪽에 든 계란은 깨지지 않은 계란을 모두 확인해서 최대값을 찾아야 함으로 모든 계란을 확인해야함
# 맨 오른쪽까지 다 확인한 경우 내구도가 0 이하인 계란을 count하여 최대값을 산출

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