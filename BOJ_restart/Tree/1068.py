# -*- coding: utf-8 -*-
# 노드의 정보가 주어졌을 때 어떤 노드를 지웠을 경우 리프 노드의 개수를 출력하는 문제
# 노드 클래스를 생성하여 부모 정보를 부여하고
# 한 노드를 제거했을 경우 그 밑의 자식 노드들을 제거하여 남은 노드 수를 출력
# 깊이 우선 탐색(dfs)로 풀이


import sys
from collections import deque

class Node():
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.child = []

N = int(input())
info = list(map(int, sys.stdin.readline().split()))
target = int(input())

tree = [Node(idx) for idx in range(N)]
for idx in range(N):
    parent = info[idx]
    tree[idx].parent = parent

    if parent != -1: tree[parent].child.append(idx)

dq = deque([target])

while dq:
    node = dq.pop()
    
    if tree[node].data == -2: continue
    else:
        if not tree[node].parent == -1:
            parent = tree[node].parent
            child_idx = tree[parent].child.index(node)
            tree[parent].child.pop(child_idx)

        tree[node].data = -2
        for child in tree[node].child: dq.append(child)

ans = 0
for idx in range(N):
    if tree[idx].data != -2 and len(tree[idx].child) == 0: ans += 1

print(ans)