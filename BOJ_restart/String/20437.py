# -*- coding: utf-8 -*-
# a~z까지 리스트를 생성하고 각각의 index 값을 넣어준다.
# 특정 알파벳의 리스트 크기가 K일 경우 마지막 인덱스-첫 인덱스+1을 ans에 append하고 첫번째 인덱스를 pop한다.
# 최종으로 ans 리스트를 sort하고 첫번쨰와 마지막 값을 출력한다.

import sys
from collections import Counter, deque

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    W = list(input().rstrip())
    K = int(input())

    _check = Counter(W)

    if max(_check.values()) < K: print(-1)
    else:
        ans = []
        idx_list = [deque() for _ in range(26)]
        idx = 0

        for ch in W:
            idx_list[ord(ch)-97].append(idx)

            if len(idx_list[ord(ch)-97]) == K:
                ans.append(idx_list[ord(ch)-97][-1]-idx_list[ord(ch)-97][0]+1)
                idx_list[ord(ch)-97].popleft()

            idx += 1

        ans.sort()
        print(str(ans[0])+" "+str(ans[-1]))


