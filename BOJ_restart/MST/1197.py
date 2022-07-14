# -*- coding: utf-8 -*-
# 사이클이 발생할 수도 있다. 따라서 MST 문제
# 크루스칼 & 프림으로 해결할 수 있고 프림으로 풀이
# 정점마다 연결되는 정보를 확인하기 위한 딕셔너리(adj), 정점 방문 여부 리스트(check), 우선순위 큐(pq), 생성
# 입력받는 각 정점의 정보를 추가하고 정점 "1"의 정보로 우선순위 큐를 초기 설정
# 우선순위 큐가 empty일 때까지 도는 것을 반복문의 조건으로 주고 우선순위 큐를 하나씩 pop
# 현재 정점과 연결된 정점 중 weight가 가장 작은 정점을 받으며 그 정점이 방문하지 않은 정점이라면 해당 weight 값을 ans에 추가하고 current 정점으로 설정
# 방문한 정점의 개수가 V와 동일해진다고 종료

import sys
import heapq

V, E = map(int, sys.stdin.readline().split())
adj = {v:[] for v in range(1, V+1)}
check = [False for _ in range(V)]
ans = 0
cnt = 0
pq = []

for _ in range(E):
    A, B, C = map(int, sys.stdin.readline().split())
    adj[A].append((C, B))
    adj[B].append((C, A))

# 우선순위 큐 초기 설정
check[0] = True
cnt += 1
for e in adj[1]: heapq.heappush(pq, (e[0], 1, e[1]))

while pq:
    weight, curr, v = heapq.heappop(pq)

    if not check[v-1]:
        curr = v
        for e in adj[curr]: heapq.heappush(pq, (e[0], v, e[1]))

        check[curr-1] = True
        ans += weight
        cnt += 1
    else: continue

    if cnt == V: break

print(ans)