# -*- coding: utf-8 -*-
# (0,0)부터 N*N값 내림차순으로 차례대로 채워넣는다.
# 처음 진행 방향을 아래로 설정하고 아래->오른쪽->위->왼쪽을 순환하며 값을 채워넣는다.
# visited 배열을 생성해 방문 체크를 해주며 방문했을 경우 or 표의 범위를 넘어갈 경우 방향을 다음 방향으로 설정한다.

import sys
input = sys.stdin.readline

N = int(input())
target = int(input())

visited = [[0]*N for _ in range(N)]
ans = [[0]*N for _ in range(N)]
target_ans = []

direction = [["y", -1], ["x", 1], ["y", 1], ["x", -1]]
value = N*N
y, x = 0, 0
curr_dir = 0

def check(way, step, y, x):
    global N, direction, curr_dir, visited

    if way == "y":
        if y+step<0 or y+step==N or visited[x][y+step]==1: curr_dir += 1
    else:
        if x+step<0 or x+step==N or visited[x+step][y]==1:
            if curr_dir == 3: curr_dir = 0
            else: curr_dir += 1

    if direction[curr_dir][0] == "y": y += direction[curr_dir][1]
    else: x += direction[curr_dir][1]

    return y, x

while value>0:
    ans[x][y] = value
    visited[x][y] = 1
    
    if target == value:
        target_ans.append(x+1)
        target_ans.append(y+1)

    value -= 1

    y, x = check(direction[curr_dir][0], direction[curr_dir][1], y, x)

for ans_ in ans: print(*ans_)
print(*target_ans)