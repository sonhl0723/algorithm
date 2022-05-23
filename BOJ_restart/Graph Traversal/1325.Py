# -*- coding: utf-8 -*-
# BFS로 문제를 풀어본다.
# 1~N까지의 모두 보면서 visited를 초기화하고 해킹이 가능한 컴퓨터의 수를 계산한다.

import sys
from collections import deque

def dfs(tree, N, answer):
    max_num = -1

    for num in range(N):
        visited = [0 for _ in range(N)]
        dq = deque(tree[num+1])
        visited[num] = 1

        while dq:
            node = dq.popleft()
            
            if visited[node-1] == 0:
                answer[num] += 1
                visited[node-1] = 1
                for elem in tree[node]:
                    if visited[elem-1] == 0: dq.append(elem)
            
        if max_num < answer[num]: max_num = answer[num]

    return answer, max_num

N, M = map(int, sys.stdin.readline().split())

tree = {}
answer = []

for num in range(N):
    tree[num+1] = []
    answer.append(0)

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    tree[b].append(a)

answer, max_num = dfs(tree, N, answer)

for idx in range(N):
    if answer[idx] == max_num: print(idx+1, end=' ')