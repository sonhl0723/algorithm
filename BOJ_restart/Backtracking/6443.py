# -*- coding: utf-8 -*-
# itertools.permutations를 사용해서 문제를 풀 경우 시간 초과가 발생
# 백트래킹을 사용해서 모든 조합을 찾아낸다.
# 모든 조합을 찾아내는 백트래킹을 구현할 때는 

import sys
 
input = sys.stdin.readline

N = int(input())

def dfs(ans_len, str_list, ans):
    if ans_len == len(ans): print(ans)
    else:
        for idx in range(ans_len):
            tmp = ans + str_list[idx]
            if tmp not in _set and visited[idx] == False:
                _set.add(tmp)
                visited[idx] = True
                dfs(ans_len, str_list, tmp)
                visited[idx] = False

for _ in range(N):
    _str = list(input().rstrip())
    _str.sort()

    visited = [False]*len(_str)
    _set = set()

    dfs(len(_str), _str, '')