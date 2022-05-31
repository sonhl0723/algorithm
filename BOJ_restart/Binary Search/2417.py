# -*- coding: utf-8 -*-
# n의 제곱근을 구하는 문제
# sqrt()를 사용해서 문제를 해결
# => 4503599627370497 에서 부동 소수점에 의한 오류발생
# 이분 탐색으로 풀이
# 최종 mid 값이 n보다 클경우는 ans=mid 작을 경우는 ans=mid+1

n = int(input())

start = 0
end = 3037000500

while start <= end:
    mid = (start+end)//2
    tmp = mid**2

    if tmp < n: start = mid+1
    else: end = mid-1

print(start)