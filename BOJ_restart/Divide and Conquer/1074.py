# -*- coding: utf-8 -*-
# 2^(N-1)을 기준으로 4분면에서의 위치를 파악
# r>=2^(N-1) && c>=2^(N-1) => 4사분면
# r>=2^(N-1) && c<2^(N-1) => 3사분면
# r<2^(N-1) && c>=2^(N-1) => 2사분면
# r<2^(N-1) && c<2^(N-1) => 1사분면
# 사분면 위치에 따라 (사분면-1)*(2^(N-1))하고 1사분면에서의 똑같은 위치로 r과 c값을 설정
# (0,0)부터 시작해 (r,c) 위치가 될 때까지 반복

import sys
input = sys.stdin.readline

N, r, c = map(int, input().split())
half = 2**(N-1)
ans = 0

def check(half, r, c):
    quat = (2**(N*2))//4
    if r>=half and c>=half:
        r -= half
        c -= half
        ans_tmp = quat*3
    elif r>=half and c<half:
        r -= half
        ans_tmp = quat*2
    elif r<half and c>=half:
        c -= half
        ans_tmp = quat
    else: ans_tmp = 0

    return r, c, ans_tmp

while 1:
    r, c, ans_tmp = check(half, r, c)
    ans += ans_tmp
    N -= 1
    half = 2**(N-1)
    if half < 2:
        half += 1
        break

dx = [0, 1, -1, 1]
dy = [0, 0, 1, 0]

y, x = 0, 0

for idx in range(4):
    y += dy[idx]
    x += dx[idx]
    
    if y == r and x == c: break
    else: ans += 1

print(ans)