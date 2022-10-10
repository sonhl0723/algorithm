# -*- coding: utf-8 -*-

import sys

input = sys.stdin.readline

T = int(input())

def check_palin(_str):
    if _str == _str[::-1]: return 0
    else:
        left, right = 0, len(_str)-1

        while left <= right:
            if _str[left] == _str[right]:
                left += 1
                right -= 1
            else:
                case1 = _str[:right]+_str[right+1:]
                case2 = _str[:left]+_str[left+1:]

                if case1 == case1[::-1] or case2 == case2[::-1] : return 1
                else: return 2

    return 0
            
for _ in range(T):
    _str = list(input().rstrip())
    print(check_palin(_str))