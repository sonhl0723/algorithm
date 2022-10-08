# -*- coding: utf-8 -*-
# '<' 문자를 감지하면 flag는 True가 되고 '>' 문자를 감지하면 flag는 False가 된다
# flag가 True일 때, ch는 바로 ans 문자열에 추가된다.
# flag가 Flase일 때, ch는 stack에 추가된다.
# flag가 True가 될 때, stack이 빌 때까지 pop하여 ans 문자열에 추가한다.
# stack이 비어있지 않을 경우 stack이 빌 때까지 pop하여 ans 문자열에 추가한다.

import sys
from collections import deque

input = sys.stdin.readline

_str = input()

flag = False
stack = deque()
ans = ''

def pop_stack(st):
    global ans
    while st:
        tmp = st.pop()
        ans += tmp

for ch in _str:
    if ch == '\n': continue

    if ch == '<':
        flag = True
        pop_stack(stack)
        ans += ch
    elif ch == '>':
        ans += ch
        flag = False
    elif ch == ' ':
        if flag: ans += ch
        else:
            pop_stack(stack)
            ans += ch
    else:
        if flag: ans += ch
        else: stack.append(ch)

pop_stack(stack)
print(ans)