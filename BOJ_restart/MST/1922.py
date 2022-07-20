# -*- coding: utf-8 -*-
# 최소 스패닝 트리를 구하는 문제
# 첫째 줄에는 컴퓨터의 개수 N, 둘째 줄에는 컴퓨터의 관계 개수 M
# 3번째 줄부터 M+2번째 줄까지 [컴퓨터1, 컴퓨터2, 연결 비용]
# 모든 컴퓨터를 연결하기 위한 최소 비용 출력
# 풀이 1. 프림 알고리즘
# 입력받은 컴퓨터 간 연결 비용과 연결되는 컴퓨터 정보를 연결 비용 작은순으로 adj 딕셔너리에 추가
# 우선순위 큐를 1번 컴퓨터의 연결 정보로 초기 설정, 1번 컴퓨터의 방문 정보를 True로 update
# 우선순위 큐(pq)가 empty일 때까지 반복문을 돌며 컴퓨터 count(cnt)가 N일 경우 stop
# 현재 고려하고 있는 컴퓨터가 방문하지 않았다면 현재 cost를 ans에 추가하고 cnt를 1 증가, 현재 고려하고 있는 컴퓨터의 연결 정보를 우선순위 큐에 추가


import sys
import heapq

N = int(input())
M = int(input())
adj = {comp:[] for comp in range(1, N+1)}
visited = [False for _ in range(N+1)]

for _ in range(M):
    a, b, c = map(int, sys.stdin.readline().split())
    heapq.heappush(adj[a], [c, b])
    heapq.heappush(adj[b], [c, a])

pq = adj[1]
visited[1] = True
cnt, ans = 1, 0

while pq:
    if cnt == N: break

    cost, dest = heapq.heappop(pq)

    if not visited[dest]:
        visited[dest] = True
        ans += cost
        cnt += 1
        for tmp_c, tmp_d in adj[dest]: heapq.heappush(pq, [tmp_c, tmp_d])

print(ans)