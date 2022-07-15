# -*- coding: utf-8 -*-
# 원을 이용한 문제는 총 5가지의 경우로 생각해야한다.
# 1. 중점이 같은 경우
#   중점이 같은 경우는 반지름의 길이를 비교하여 완전 동일한 원 or 만나지 않는 원 판별
# 2. 외접인 경우
#   r1+r2 == d
# 3. 내접인 경우
#   abs(r1-r2) == d
# 4. 만나지 않는 경우
#   r1+r2 < d or (abs(r1-r2) > d and r1!=r2)
# 5. 서로 다른 두 점에서 만나는 경우
#   abs(r1-r2) < d < r1+r2

import sys

T = int(input())

def check_neg(a, b):
    # a, b 둘다 음수
    if a < 0 and b < 0:
        a, b = abs(a), abs(b)
        if a <= b: return b-a
        else: return a-b
    # 한 쪽만 음수
    elif a < 0: return b-a
    else: return a-b

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())

    x_dis = check_neg(x1, x2)
    y_dis = check_neg(y1, y2)

    dis = (x_dis**2)+(y_dis**2)

    if dis == 0:
        if r1 == r2: print(-1)
        else: print(0)
    elif abs(r1-r2)**2 == dis or (r2+r1)**2 == dis: print(1)
    elif abs(r1-r2)**2 < dis and (r2+r1)**2 > dis: print(2)
    else: print(0)