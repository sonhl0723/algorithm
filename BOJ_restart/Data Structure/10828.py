# -*- coding: utf-8 -*- 

# LIFO 문제였는데 deque 모듈을 사용해서 문제를 풀었다.
# 하지만 리스트로 풀었을 때가 걸리는 시간과 메모리 측면에서 더 좋았다.
# 그 이유는 LIFO일 경우 첫 번째 요소에만 접근하면 되기 때문에 O(1)의 효율성으로 가능하기 때문이다.

from collections import deque
import sys

N = int(input())

dq = deque()

for _ in range(N):
    myinput = sys.stdin.readline().rstrip()
    if 'push' in myinput:
        a, b = myinput.split()
        if a == 'push':
            dq.appendleft(b)
    else:
        if myinput == 'pop':
            if dq: print(dq.popleft())
            else: print("-1")
        elif myinput == 'top':
            if dq:
                tmp = dq.popleft()
                dq.appendleft(tmp)
                print(tmp)
            else: print("-1")
        elif myinput == 'size': print(len(dq))
        elif myinput == 'empty':
            if len(dq)==0: print("1")
            else: print("0")