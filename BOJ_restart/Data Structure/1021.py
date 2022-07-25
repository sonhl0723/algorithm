# -*- coding: utf-8 -*-
# 덱을 사용하는 자료 구조 문제
# 추출하려는 값의 인덱스를 확인하여 현재 덱 길이의 중간보다 크면 3번째 연산, 작거나 같으면 2번째 연산을 수행하여 추출

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())
dq = deque()
ans = 0

for i in range(1, N+1): dq.append(i)

input_ = list(map(int, sys.stdin.readline().split()))

for target in input_:
    idx = list(dq).index(target)

    if idx <= N//2:
        while idx > 0:
            tmp = dq.popleft()
            dq.append(tmp)
            idx -= 1
            ans += 1
    else:
        idx = N - idx - 1
        while idx >= 0:
            tmp = dq.pop()
            dq.appendleft(tmp)
            idx -= 1
            ans += 1
    
    dq.popleft()
    N -= 1

print(ans)