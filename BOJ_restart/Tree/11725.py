# -*- coding: utf-8 -*-
# 입력으로 a, b를 받고 a 혹은 b가 1일 경우 1이 아닌 수의 부모 노드를 1로 설정한다.
# a와 b 모두 1이 아닌 경우 a와 b 중 부모 노드가 있는 수를 다른 수의 부모 노드로 설정한다.
# ==> 리스트로 해결하려고 했으나 N이 최대 100,000이므로 메모리 256MB 제한이기 때문에 해결하지 못한다.
# 노드를 생성하여 문제를 해결한다.
# tree 리스트 안에 2~N까지의 노드를 생성하고 입력에 따라 부모 노드를 지정해준다.
# 만약 a, b가 root가 지정되어 있지 않다면 connection으로 서로를 지정해주고 입력을 다 받은 후 connection의 root를 보며 재귀함수를 통해 부모 노드를 찾는다.
# ==> 재귀의 깊이가 길어지며 런타임 에러가 발생 & 메모리 초과
# root 노드인 1부터 자식 노드의 부모 노드를 찾는 형태로 문제를 해결하기 위해 BFS로 해결해보기로했다.
# 1~N까지의 set으로 이루어진 리스트를 생성하고 a, b 입력을 받으면 각각의 set에 상대방을 추가한다.
# 1부터 BFS를 돌며 자식 노드의 부모 노드를 result에 저장한다.

import sys
from collections import deque

N = int(input())
source = [set() for _ in range(N)]
answer = [0] * (N-1)

def bfs(source, node):
    dq = deque()
    dq.append(node)
    
    while dq:
        parent = dq.popleft()

        for elem in source[parent-1]:
            if elem != 1 and answer[elem-2] == 0:
                answer[elem-2] = parent
                dq.append(elem)
        
for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    source[a-1].add(b)
    source[b-1].add(a)
bfs(source, 1)

for ans in answer: print(ans)