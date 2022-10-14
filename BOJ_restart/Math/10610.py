# -*- coding: utf-8 -*-
# 30의 배수임을 아는 방법
# 1. 모든 자리의 숫자의 합이 30의 배수여야한다.

import sys

input = sys.stdin.readline

tar = list(map(int, input().rstrip()))

tar = sorted(tar, reverse=True)

if sum(tar)%3 != 0 or tar[-1] != 0: print(-1)
else:
    ans = ''
    for elem in tar: ans += str(elem)

    print(ans)