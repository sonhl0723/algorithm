# -*- coding: utf-8 -*-
# row를 기준으로 요소들의 합을 저장하며 테이블에 저장한다.
# row를 기준으로 x1에서 x2까지 반복문을 돌며 y2 x_i에서 y1 x_i-1의 값을 answer에 더한다.
# 최종 answer를 출력한다.
# ==> 이 방법으로 했을때는 row가 많을 경우 시간초과가 발생하게 된다.
# (0,0)을 기준으로 각 위치까지의 사각형 넓이의 합을 테이블에 저장한다.
# 주어진 사각형의 넓이를 구하기 위해서 (x2, y2)에서 (x1, y2)와 (x2, y1)을 빼주고 (x1-1, y1-1)을 더해준다.

import sys

N, M = map(int, sys.stdin.readline().rstrip().split())

table = [[0]*N for _ in range(N)]

for x in range(N):
    tmp = 0
    table_input = map(int, sys.stdin.readline().rstrip().split())
    for y, input in enumerate(table_input):
        if x == 0 and y == 0: table[x][y] = input
        elif x == 0: table[x][y] = input + table[x][y-1]
        elif y == 0: table[x][y] = input + table[x-1][y]
        else: table[x][y] = input + table[x][y-1] + table[x-1][y] - table[x-1][y-1]

for _ in range(M):
    answer = 0
    x1, y1, x2, y2 = map(
        lambda a: a-1, (map(int, sys.stdin.readline().rstrip().split())))

    if x1 == 0 and y1 == 0: answer = table[x2][y2]
    elif x1 == 0: answer = table[x2][y2] - table[x2][y1-1]
    elif y1 == 0: answer = table[x2][y2] - table[x1-1][y2]
    else: answer = table[x2][y2] - table[x2][y1-1] - table[x1-1][y2] + table[x1-1][y1-1]

    print(answer)