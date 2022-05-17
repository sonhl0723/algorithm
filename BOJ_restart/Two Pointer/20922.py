# -*- coding: utf-8 -*-
# 수열을 입력받고 set으로 중복을 제거한 후 반복을 체크하기 위해서 딕셔너리를 생성한다.
# 입력받은 수열을 처음부터 끝까지 확인하면서 어떠한 수가 K개 초과 반복한다면 해당 수가 K개 미만인 곳과 지금까지의 수열의 길이를 확인한다.

import sys

N, K = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
check = {i:[0, 0] for i in set(arr)}
answer = 0
tmp = 0
start = 0
end = 0

while end < N:
    check[arr[end]][0] += 1

    if check[arr[end]][0] > K:
        while check[arr[end]][0] > K:
            check[arr[start]][0] -= 1
            start += 1

    tmp = end - start + 1

    answer = max(answer, tmp)
    end += 1

if tmp == 0: tmp = end - start
print(max(answer, tmp))