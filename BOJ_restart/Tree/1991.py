# -*- coding: utf-8 -*-
# 노드 구조체를 생성하여 해당 노드의 값, 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드를 지정해주고 DFS로 문제를 해결한다.
# preorder, inorder, postorder 함수를 각각 생성한다.
# preorder는 방문하는 노드마다 answer에 추가하고 오른쪽-왼쪽 자식 순서로 stack에 추가하며 stack이 빌 때까지 반복한다.
# inorder는 방문하는 노드를 visit 체크해주며 visited했었거나 left 노드가 없을 경우 answer에 추가하고 그렇지 않을 경우 오른쪽-부모-왼쪽 노드 순으로 stack에 추가하며 stack이 빌 때까지 반복한다.
# postorder는 방문하는 노드를 visit 체크해주며 visited했었거나 자식 노드가 둘 다 없을 경우 answer에 추가하고 그렇지 않을 경우 부모-오른쪽-왼쪽 노드 순으로 stack에 추가하며 stack이 빌 때까지 반복한다.

import sys

N = int(input())

class Node():
    def __init__(self, data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None

def dfs_preorder(tree, root):
    stack = []
    stack.append(root)
    answer = ''

    while stack:
        node = tree[stack.pop()]
        answer += node.data

        if node.right != '.': stack.append(node.right)
        if node.left != '.': stack.append(node.left)

    return answer

def dfs_inorder(tree, root):
    stack = []
    stack.append(root)
    visited = {alpha : False for alpha in tree.keys()}
    answer = ''

    while stack:
        node = tree[stack.pop()]
        
        if visited[node.data]:
            answer += node.data
            continue
        else: visited[node.data] = True

        if node.right != '.': stack.append(node.right)
        if node.left != '.':
            stack.append(node.data)
            stack.append(node.left)
        else: answer += node.data

    return answer

def dfs_postorder(tree, root):
    stack = []
    stack.append(root)
    visited = {alpha : False for alpha in tree.keys()}
    answer = ''

    while stack:
        node = tree[stack.pop()]
        left_flag = False
        right_flag = False

        if visited[node.data]:
            answer += node.data
            continue
        else: visited[node.data] = True

        if node.left == '.': left_flag = True
        if node.right == '.': right_flag = True

        if left_flag and right_flag: answer += node.data
        elif not left_flag or not right_flag: stack.append(node.data)

        if not right_flag: stack.append(node.right)
        if not left_flag: stack.append(node.left)

    return answer


tree = {chr(65+i):Node(chr(65+i)) for i in range(N)}

for _ in range(N):
    parent, left, right = sys.stdin.readline().split()

    tree[parent].left = left
    tree[parent].right = right
    if left != '.': tree[left].parent = parent
    if right != '.': tree[right].parent = parent

print(dfs_preorder(tree, 'A'))
print(dfs_inorder(tree, 'A'))
print(dfs_postorder(tree, 'A'))