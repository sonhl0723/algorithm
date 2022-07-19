# -*- coding: utf-8 -*-
# 총 10개의 컴퓨터가 있고 데이터의 마지막 번호에 따라 컴퓨터의 종류가 결정된다.
# a, b가 주어지면 총 데이터 개수는 a^b이다.
# a를 b만큼 곱해주는 반복문을 생성한 다음 숫자가 커지지 않도록 10으로 모듈러 연산을 한다.
# 최종 나머지값에 따라 컴퓨터의 종류를 결정한다.
# => 시간 초과
# a의 거듭제곱이 몇 번마다 반복되는지 체크하여 풀이
# 마지막 자리가 반복되는 것을 확인하기 위해 set, 최종 값에 접근하기 위한 리스트를 선언
# 반복되는 수의 개수로 b를 나눈 나머지를 리스트에 인덱싱하고 해당 값이 0일 경우는 10을 출력, 이외는 해당 값을 출력

import sys

T = int(input())
    
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    ans_set = set([a%10])
    ans_list = [a%10]
    ans_set_len = 1
    tmp = a

    for _ in range(b-1):
        tmp = (tmp*a)%10
        ans_set.add(tmp)
        if ans_set_len == len(ans_set): break
        else:
            ans_list.append(tmp)
            ans_set_len += 1

    b = b % ans_set_len

    if ans_list[b-1] == 0: print(10)
    else: print(ans_list[b-1])