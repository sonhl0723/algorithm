# -*- coding: utf-8 -*-
# math 모듈로 최대공약수를 구하고 투포인터로 해당 수의 모든 약수를 찾는다.
# ==> 시간초과
# 모든 약수를 구하기 위해서는 해당 값의 제곱근까지만 확인하면된다.

import sys
import math

n = int(input())

arr = list(map(int, sys.stdin.readline().split()))
ans = set()

if n == 2:
    mygcd = math.gcd(arr[0], arr[1])
else:
    mygcd = math.gcd(arr[0], arr[1])
    mygcd = math.gcd(mygcd, arr[2])

for i in range(1, int(math.sqrt(mygcd)+1)):
    if mygcd%i == 0:
        ans.add(i)
        ans.add(mygcd//i)

print(*sorted(ans))