# -*- coding: utf-8 -*-
# 1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열을 모두 출력
# 1<=M<=N<=8, 출력은 사전순으로 증가

import sys

N, M = map(int, sys.stdin.readline().split())

ans = []

def dfs():
    global ans, N, M

    if len(ans) == M:
        print(*ans)
        return

    for idx in range(1, N+1):
        if idx in ans: continue

        ans.append(idx)
        dfs()
        ans.pop()
        
dfs()