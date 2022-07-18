# -*- coding: utf-8 -*-
# 사이클이 생기지 않고 순서를 고려해 최종적으로 걸리는 시간을 도출하는 문제이므로 위상 정렬로 풀이
# 최종적으로 건물을 건설하기 위한 최대 시간을 확인하여 출력
# indegree를 확인할 수 있는 딕셔너리(indeg), 건설 시간 확인을 위한 리스트(delay), 최종적으로 걸리는 시간을 확인하기 위한 리스트(ans) 선언
# indegree가 0인 건물을 큐에 추가하고 큐의 top이 최종 건물일 경우 stop

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