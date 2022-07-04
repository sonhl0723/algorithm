# -*- coding: utf-8 -*- 

import sys
import copy

def opp_check(board, way, color, start):
    _start = copy.deepcopy(start)
    _color = color
    if way[0] == 1: dy = -1
    elif way[0] == -1: dy = 1
    else: dy = 0

    if way[1] == 1: dx = -1
    elif way[1] == -1: dx = 1
    else: dx = 0

    if _start[0]+dy >= 0 and _start[0]+dy < 19 and _start[1]+dx >= 0 and _start[1]+dx < 19:
        _start[0] += dy
        _start[1] += dx
    else: return True

    if board[_start[0]][_start[1]] != _color: return True
    else: return False

def cons_check(board, way, color, start):
    _start = copy.deepcopy(start)
    _color = color
    dx = way[1]
    dy = way[0]
    _flag = 1

    while True:
        if _start[0]+dy >= 0 and _start[0]+dy < 19 and _start[1]+dx >= 0 and _start[1]+dx < 19:
            _start[0] += dy
            _start[1] += dx

            if board[_start[0]][_start[1]] == _color: _flag += 1
            else: break

        else: break

    if _flag == 5 and opp_check(board, way, color, start): return True
    else: return False

board = []
line_dx = [-1, 0, 1, 0]
line_dy = [0, -1, 0, 1]
opp_dx = [-1, -1, 1, 1]
opp_dy = [-1, 1, -1, 1]
dx, dy = 0, 0
ans = [-1, -1, -1]

for _ in range(19): board.append(list(map(int, sys.stdin.readline().split())))

for x in range(19):
    end = False
    for y in range(19):
        color = board[y][x]

        if color==0: continue
        
        for idx in range(4):
            if cons_check(board, [line_dy[idx], line_dx[idx]], color, [y, x]):
                ans[0], ans[2] = color, x
                dx, dy = line_dx[idx], line_dy[idx]
                end = True
                break

            if cons_check(board, [opp_dy[idx], opp_dx[idx]], color, [y, x]):
                ans[0], ans[2] = color, x
                dx, dy = opp_dx[idx], opp_dy[idx]
                end = True
                break

        if end: break

    if end:
        ans[1] = y
        break

if ans[0] == -1: print(0)
else: print(str(ans[0])+'\n'+str(ans[1]+1)+' '+str(ans[2]+1))