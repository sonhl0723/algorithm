# -*- coding: utf-8 -*-

import sys

n = int(input())
five_num = int(n/5)
n = int(n%5)

while five_num>0 or n>=2:
    two_num = int(n/2)
    n = int(n%2)

    if n == 0: break
    elif five_num>0:
        n += two_num*2
        n += 5
        five_num -= 1

if n != 0: print("-1")
else: print(five_num+two_num)