# -*- coding: utf-8 -*-
# 인접 행렬이 주어졌을 때 간선이 존재하는 곳은 1로 채웠을 때의 최종 행렬을 출력
# 플로이드 알고리즘으로 풀이

import sys

N = int(input())

map_ = []
for _ in range(N): map_.append(list(map(int, sys.stdin.readline().split())))

for k in range(N):
    for i in range(N):
        for j in range(N):
            if map_[i][j] == 0:
                if map_[i][k] == 1 and map_[k][j] == 1: map_[i][j]= 1

for idx in range(N): print(*map_[idx][:])