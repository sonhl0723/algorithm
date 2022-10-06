# -*- coding: utf-8 -*-
# 모든 경우의 수를 고려하되 중복되는 값은 고려하지 않는다.
# 배열은 H, T 두 가지로 구성되어 있기 때문에 0, 1로 치환하여 2진수로 치환하여 중복을 체크한다.
# 최소값을 구하기 위해 추가 작업이 필요없게 bfs로 풀이

import sys
from collections import deque
from copy import deepcopy

input = sys.stdin.readline

T = int(input())

def make_binary(_map):
    _binary = ""

    for i in range(3):
        for j in range(3): _binary += str(_map[i][j])

    return _binary

def bfs(_stack, visited):
    while _stack:
        origin_map, tmp_cnt = _stack.popleft()

        tmp_bin = int(make_binary(origin_map), 2)

        if tmp_bin == 0 or tmp_bin == 511: return tmp_cnt

        if visited[tmp_bin]: continue
        else: visited[tmp_bin] = True

        # 열 기준
        for i in range(3):
            tmp_map = deepcopy(origin_map)
            for j in range(3):
                if tmp_map[j][i] == 1: tmp_map[j][i] = 0
                else: tmp_map[j][i] = 1

            _stack.append([tmp_map, tmp_cnt+1])

        # 행 기준
        for i in range(3):
            tmp_map = deepcopy(origin_map)
            for j in range(3):
                if tmp_map[i][j] == 1: tmp_map[i][j] = 0
                else: tmp_map[i][j] = 1
            
            _stack.append([tmp_map, tmp_cnt+1])

        # 대각 기준
        tmp_map = deepcopy(origin_map)
        for i in range(3):
            if tmp_map[i][i] == 1: tmp_map[i][i] = 0
            else: tmp_map[i][i] = 1
        
        _stack.append([tmp_map, tmp_cnt+1])

        tmp_map = deepcopy(origin_map)
        for i in range(3):
            if tmp_map[2-i][i] == 1: tmp_map[2-i][i] = 0
            else: tmp_map[2-i][i] = 1

        _stack.append([tmp_map, tmp_cnt+1])

    return -1

for _ in range(T):
    _map = []

    for _ in range(3):
        tmp = list(input().split())
        for idx in range(3):
            if tmp[idx] == "H": tmp[idx] = 1
            else: tmp[idx] = 0

        _map.append(tmp)

    visited = [False]*512
    _stack = deque()
    _stack.append([_map, 0])

    print(bfs(_stack, visited))