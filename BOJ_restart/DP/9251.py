# -*- coding: utf-8 -*-
# 두 문자열의 최장 수열의 길이를 구하는 문제
# 이중 for문을 사용하여 두 문자열을 모두 탐색한다. O(2N)
# 여기서 핵심은 같은 문자를 비교하는 비교식보다 이전의 최대값을 선정하는 비교식이 우선이되어야한다.

import sys

input = sys.stdin.readline

_str1 = list(input().rstrip())
_str2 = list(input().rstrip())

idx, len1, len2 = 0, len(_str1), len(_str2)
ans = [0]*len2

for i in range(len1):
    cnt = 0
    for j in range(len2):
        if cnt < ans[j]: cnt = ans[j]
        elif _str1[i] == _str2[j]: ans[j] = cnt+1

print(max(ans))