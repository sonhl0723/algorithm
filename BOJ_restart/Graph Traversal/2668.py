# -*- coding: utf-8 -*-
# 첫 번째 줄에서 뽑은 집합과 두 번째 줄에서 뽑은 집합의 일치하는 최대 개수와 요소를 출력
# 사이클이 발생하는 모든 요소를 체크
# 깊이 우선 탐색(dfs)풀이
# ---풀이
# N개의 key를 가지는 딕셔너리와 방문 체크를 위한 visited 리스트 생성
# 1~N까지 key를 반복문으로 dfs 돌리며 사이클이 발생했을 경우 요소를 ans 리스트에 추가

from collections import deque

N = int(input())
my_input = {key:[] for key in range(1, N+1)}
ans = set()

for key in range(1, N+1): my_input[key].append(int(input()))

def dfs(key, visited):

    visited[key] = 1

    for elem in my_input[key]:
        if visited[elem] == 0: dfs(elem, visited)
        else:
            if elem not in ans:
                ans.add(key)
                ans.add(elem)
                visited[elem] = 1

for key in range(1, N+1):
    visited = [0]*(N+1)
    dfs(key, visited)

ans = list(ans)
ans.sort()
print(len(ans))
for ans_ in ans: print(ans_)