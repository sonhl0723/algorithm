# -*- coding: utf-8 -*-

import sys

N = sys.stdin.readline().split()[0]

if len(N) <= 1: N = "0"+N

a = int(N[1])
b = int(str(int(N[0])+int(N[1]))[-1])
ans = 1

while str(a)+str(b) != N:
    tmp = a
    a = b
    b = int(str(b+tmp)[-1])

    ans += 1

print(ans)