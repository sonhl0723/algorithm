# -*- coding: utf-8 -*-
# 이분 탐색으로 해결했지만 in이 더 빠르다.
# 이분 탐색으로 해결하려면 input을 정렬해야하기 때문에 정렬하지 않고 in으로 원소를 찾는 것이 더 빠른 것이라고 예상한다.

import sys

N = int(input())
have = set(map(int, sys.stdin.readline().split()))
M = int(input())
find = list(map(int, sys.stdin.readline().split()))

have = sorted(have)

ans = ""

for idx in range(M):
    start = 0
    end = N-1
    find_flag = False

    while start <= end:
        mid = (start+end)//2

        if have[mid] == find[idx]:
            find_flag = True
            break
        elif have[mid] < find[idx]: start = mid+1
        else: end = mid-1
    
    if find_flag: ans += "1 "
    else: ans += "0 "

print(ans[:-1])