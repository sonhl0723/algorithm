# -*- coding: utf-8 -*-
# 4등분 씩 분할하여 최종 결과를 도출해내는 문제이다.
# queue를 사용하여 정사각형으로 인접한 4개의 숫자를 순서대로 queue에 삽입하고 4개를 비교하여 2번째로 큰 숫자를 row 기준으로 배열에 삽입한다.
# 이러한 과정을 숫자 1개만 남을 때 까지 반복한다.

import sys
from collections import deque

N = int(input())
arr = []
dq = deque()
col, row = 0, 0
arr_tmp = []

for idx in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    arr.append(tmp)

while N>1:
    for row in range(0, N, 2):
        for col in range(0, N, 2):
            dq.append(arr[row][col])
            dq.append(arr[row][col+1])
            dq.append(arr[row+1][col])
            dq.append(arr[row+1][col+1])

    N = N//2
    arr = [[] for _ in range(N)]
    idx = 0
    flag = 1

    while len(dq)>1:
        for _ in range(4):
            tmp = dq.popleft()
            arr_tmp.append(tmp)

        arr_tmp.sort()
        arr[idx].append(arr_tmp[-2])
        arr_tmp = []

        if flag == N:
            idx += 1
            flag = 1
        else: flag += 1
        
        if idx >= N: idx = 0

print(arr[0][0])