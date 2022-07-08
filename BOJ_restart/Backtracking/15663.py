# -*- coding: utf-8 -*-
# 수열 원소의 길이 N, 출력할 수열의 길이 M
# 조건: 수열은 사전 순으로 출력
#       중복된 수열은 출력하지 않음
# 풀이: 수열을 사전 순으로 출력하기 위해 수열 원소를 오름차순으로 정렬
#       같은 원소인지 확인할 check 리스트와 같은 수열인지 확인할 check_ans 리스트 생성
#       수열(ans)의 길이가 M일 경우 ans를 문자열로 묶어 해당 문자열이 check_ans 리스트에 존재하는지 확인
#       존재하지 않을 경우 출력 후 check_ans에 추가
#       list_의 모든 원소를 확인하며 현재 수열(ans)를 이루는 원소가 중복되지 않도록 중복 체크
#       중복하지 않는 경우 수열(ans)에 list_[idx]추가 + check 리스트에 idx 추가

import sys

N, M = map(int, sys.stdin.readline().split())

list_ = list(map(int, sys.stdin.readline().split()))
list_.sort()
ans = []
check = []
check_ans = set()
check_ans_len = 0

def dfs():
    global ans, list_, N, M, check_ans, check_ans_len

    if len(ans) == M:
        tmp = ''.join(ans)
        check_ans.add(tmp)
        if check_ans_len != len(check_ans):
            print(*ans)
            check_ans_len += 1
        return

    for idx in range(0, N):
        if idx in check: continue
        ans.append(str(list_[idx]))
        check.append(idx)
        dfs()
        ans.pop()
        check.pop()

dfs()