# -*- coding: utf-8 -*-

import sys

N, B = sys.stdin.readline().split()
# ans = 0
# seq = len(N)-1

# for idx in range(seq,-1,-1):
#     if ord(N[idx]) >= 65: target = ord(N[idx])-55
#     else: target = int(N[idx])

#     ans += ((int(B)**(seq-idx))*target)

# print(ans)

print(int(N, base=int(B)))