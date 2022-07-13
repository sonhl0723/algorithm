# -*- coding: utf-8 -*-
# 줄 세우기 문제이므로 사이클이 존재하지 않는다. 따라서 위상 정렬로 풀이
# indegree 확인을 위한 딕셔너리(deg)와 정답을 위한 배열(ans), 조건이 주어졌는지 확인하기 위한 배열(visited) 선언
# 줄 세우기 조건을 받으며 B로 주어진 학생을 A의 [0]번째 배열에 추가하여 B 학생의 indegree를 1 증가, 조건이 주어졌음을 확인하기 위해 visited[학생-1]를 True로 설정
# 초기 큐에 indegree가 0인 조건과 조건이 주어진 학생들을 추가, 그 이외의 학생들은 visited를 다시 False로 설정
# 큐가 empty가 될 때까지 반복문을 돌며 pop할 때마다 정답 배열에 해당 학생을 추가
# 현재 학생 뒤에 나와야 하는 학생들을 확인하며 확인하는 학생의 indegree가 0일 경우 visited[학생-1]을 True로 설정하고 큐에 추가
# 조건이 주어지지 않은 학생들이 있을 수 있으므로 1부터 N까지 반복문을 돌며 visited가 False인 학생들을 정답 배열에 추가

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
deg = {stu:[[], 0] for stu in range(1, N+1)}
ans = []
visited = [False for _ in range(N)]
q = deque()

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    deg[A][0].append(B)
    visited[A-1] = True
    deg[B][1] += 1

for key in deg.keys():
    if deg[key][1] == 0 and visited[key-1]: q.append(key)
    else: visited[key-1] = False

while q:
    key = q.popleft()

    ans.append(key)
    visited[key-1] = True

    for elem in deg[key][0]:
        if deg[elem][1] > 0: deg[elem][1] -= 1

        if deg[elem][1] == 0 and not visited[elem-1]:
            q.append(elem)
            visited[elem-1] = True

    deg[key][0] = []

if len(ans) < N:
    for stu in range(N):
        if not visited[stu]: ans.append(stu+1)

print(ans)