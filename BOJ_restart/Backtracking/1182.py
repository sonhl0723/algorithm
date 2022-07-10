# -*- coding: utf-8 -*-
# 값이 S가 되는 입력받은 원소들의 모든 조합을 확인해야하기 때문에 깊이 우선 탐색(dfs)로 문제를 해결
# 종료 조건 : 참조하는 원소의 index == N
# 종료 조건을 만족할 때 현재까지의 sum과 S를 비교하여 ans를 update
# 참조하는 원소를 더하는 경우와 더하지 않는 경우 총 2가지의 경우로 dfs를 재귀
# *** S가 0일 경우 아무것도 더하지 않았을 경우 또한 정답으로 치기 때문에 S가 0일 경우는 초기 ans를 -1로 설정

import sys

N, S = map(int, sys.stdin.readline().split())

list_ = list(map(int, sys.stdin.readline().split()))
list_.sort()

if S == 0: ans = -1
else: ans = 0

def dfs(idx, sum):
    global ans, N, S, list_

    if idx == N:
        if sum == S: ans += 1
        return
    
    dfs(idx+1, sum+list_[idx])
    dfs(idx+1, sum)

dfs(0, 0)

print(ans)