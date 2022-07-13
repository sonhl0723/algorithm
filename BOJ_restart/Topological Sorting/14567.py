# -*- coding: utf-8 -*-
# 각 노드에 관해서 싸이클이 존재하지 않는 문제이므로 위상 정렬로 풀이
# indegree를 확인하기 위한 딕셔너리(deg)와 정답을 위한 배열(ans)
# 각 과목에 대한 숫자를 키 값으로 value 값을 [다음에 들을 수 있는 과목, indegree]로 설정
# N개 만큼 과목의 관계를 받고 B 값으로 들어온 과목은 indgree+=1
# 초기에 indgree가 0인 과목들을 큐에 추가
# 큐가 empty일 때까지 pop하여 해당 과목 다음에 수강할 과목에 대한 indgree값을 -1해주고 그 과목의 indgree가 0이 될 경우
# 해당 과목에 대한 ans에 선 수강 과목의 ans를 더해주고 큐에 추가한다.

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
deg = {}
ans = []
q = deque()

for sub in range(1, N+1):
    deg[sub] = [[], 0]
    ans.append(1)

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    deg[A][0].append(B)
    deg[B][1] += 1

for key in deg.keys():
    if deg[key][1] == 0: q.append(key)

while q:
    key_ = q.popleft()

    for elem in deg[key_][0]:
        if deg[elem][1] > 0: deg[elem][1] -= 1

        if deg[elem][1] == 0:
            q.append(elem)
            ans[elem-1] += ans[key_-1]
        else: continue

    deg[key_][0] = []

print(ans)