# -*- coding: utf-8 -*-
# 사이클이 생기지 않고 순서를 고려해 최종적으로 걸리는 시간을 도출하는 문제이므로 위상 정렬로 풀이

import sys
from collections import deque

T = int(input())

for _ in range(T):
    N, K = map(int, sys.stdin.readline().split())

    delay = list((map(int, sys.stdin.readline().split())))
    indeg = {build:[[],0] for build in range(1, N+1)}

    for _ in range(K):
        a, b = map(int, sys.stdin.readline().split())
        indeg[a][0].append(b)
        indeg[b][1] += 1

    win = int(input())

    q = deque([])
    ans = [delay[idx] for idx in range(N)]

    for build in range(1, N+1):
        if indeg[build][1] == 0:
            indeg[build][1] = delay[build-1]
            q.append(build)

    while q:
        curr = q.popleft()

        if curr == win: break

        for next_ in indeg[curr][0]:
            indeg[next_][1] -= 1
            ans[next_-1] = max(ans[next_-1], delay[next_-1]+ans[curr-1])

            if indeg[next_][1] == 0: q.append(next_)

    print(ans[win-1])