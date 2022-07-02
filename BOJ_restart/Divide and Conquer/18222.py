# -*- coding: utf-8 -*-
# 최대 10^18이 입력으로 들어오기 때문에 시간을 지키려면 점화식을 이용해서 풀어야함

k = int(input())-1

def rec(idx):
    if idx == 0: return 0
    elif idx == 1: return 1
    else:
        if idx%2==0: return rec(idx//2)
        else: return 1-rec(idx//2)

print(rec(k))