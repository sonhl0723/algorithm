# -*- coding: utf-8 -*-
# 투포인터로 풀이할 경우 시간복잡도가 O(2N^M)이 되기 때문에 이분탐색 O(2MlogN)으로 풀이
# 범위 안 요소들의 개수를 파악하는 문제 -> 인덱스를 이분 탐색으로 탐색


import sys
import bisect

input = sys.stdin.readline

N, M = map(int, input().split())
_list = list(map(int, input().split()))
answer = []

_list.sort()

# 이분탐색 구현
# def find_lowest(val):
#     global _list, N
#     s, e = 0, N-1

#     while s <= e:
#         mid = (s+e)//2

#         if val <= _list[mid]: e = mid-1
#         else: s = mid+1
    
#     return e

# def find_largest(val):
#     global _list, N
#     s, e = 0, N-1

#     while s <= e:
#         mid = (s+e)//2

#         if val < _list[mid]: e = mid-1
#         else: s = mid+1
    
#     return e

for _ in range(M):
    l, r = map(int, input().split())

    # 이분탐색 구현
    # l_idx = find_lowest(l)
    # r_idx = find_largest(r)

    l_idx = bisect.bisect_left(_list, l)
    r_idx = bisect.bisect_right(_list, r)

    ans = r_idx-l_idx
    
    if ans <= 0: answer.append(0)
    else: answer.append(ans)

for ans in answer: print(ans)