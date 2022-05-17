# -*- coding: utf-8 -*-

import sys

N, X = map(int, sys.stdin.readline().split())
arr = []
arr = list(map(int, sys.stdin.readline().split()))
start = 0
last = X
tmp = 0
for i in range(X): tmp += arr[start+i]
answer = [tmp, 1]

while last <= N-1:
    tmp -= arr[start]
    tmp += arr[last]

    if answer[0] == tmp: answer[1] += 1
    elif answer[0] > tmp: pass
    else:
        answer[0] = tmp
        answer[1] = 1

    start += 1
    last += 1

if answer[0] != 0:
    print(answer[0])
    print(answer[1])
else: print("SAD")