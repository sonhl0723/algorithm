# -*- coding: utf-8 -*-
# 약수의 개수와 약수가 주어질 때 원래 숫자를 구하는 문제
# 약수를 오름차순으로 정렬하여 제일 작은 수와 제일 큰 수를 곱한 값을 출력

import sys

N = int(input())
elem = list(map(int, sys.stdin.readline().split()))

elem.sort()
print(elem[0]*elem[-1])