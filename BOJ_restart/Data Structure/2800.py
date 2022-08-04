# -*- coding: utf-8 -*-
# 괄호가 포함된 수학식을 입력받아 괄호를 조합하여 나올 수 있는 모든 조합을 사전순으로 출력
# 수학식의 최대 길이는 200, 괄호 쌍은 최대 10개
# ---풀이 1
# 괄호 쌍에 대한 index 정보를 저장하고 괄호쌍에 대한 (괄호쌍 의 개수-1)~0까지의 모든 조합을 구함
# 괄호쌍의 조합들을 모두 참조하며 수식을 출력

import sys
from itertools import combinations
from collections import deque

equation = sys.stdin.readline()[:-1]
stack = deque()
parentheses = []
final_check = []
ans = set()
idx, end_idx = 0, 0

for ch in equation:
    if ch == '(': stack.append(idx)
    elif ch == ')':
        top = stack.pop()
        parentheses.append([top, idx])
        final_check.append(top)
        final_check.append(idx)
    idx += 1

prt_len = len(parentheses)-1
eq_len = len(equation)

while prt_len > 0:
    comb = list(combinations(parentheses, prt_len))

    for comb_elem in comb:
        comb_elem = sum(comb_elem, [])
        tmp = ''
        
        for idx in range(eq_len):
            if idx not in comb_elem: tmp += equation[idx]

        ans.add(tmp)
    prt_len -= 1

tmp = ''
for idx in range(eq_len):
    if idx not in final_check: tmp += equation[idx]

ans.add(tmp)
ans = list(ans)
ans.sort()

for ans_ in ans: print(ans_)