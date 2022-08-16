# -*- coding: utf-8 -*-
# S의 인자를 0과 1로 변환하며 홀수 다음 짝수가 나오는 idx값 리스트를 생성
# start 인덱스값부터 시작하여 오른쪽 인자들을 확인
# 고려하는 인자가 짝수일 경우 ans_tmp 1증가, 홀수일 경우 flag 1증가
# flag가 K+1일 경우 ans 최대값으로 update
# --> 시간 초과
# 홀수 다음 짝수가 나오는 idx값을 처음부터 끝까지 돌며 찾는 것이 아닌 카운트를 하며 체크하여 stack에 추가
# --> 시간 초과
# 풀이 2
# 홀수와 짝수의 연속된 개수로 이루어진 배열을 생성(홀수: 음수 / 짝수: 양수)
# 2개의 포인터를 두어 my_list[idx]값이 음수이면 flag에 추가, 양수이면 ans_tmp에 추가
# flag>=N+1 or idx==N-1일 때 ans update
# --> 시간 초과 - 순회+@를 하게 되면 시간 초과가 발생한다고 판단, 오로지 1번의 순회만으로 풀이
# 풀이 3
# start와 end 두 포인터를 설정
# 홀수 개수가 최대치를 넘지 않을 경우 끝점을 다음으로 이동 + 정답 최대값으로 최신화
# 홀수 개수가 최대치를 넘을 경우 시작점을 다음으로 이동

import sys
import time
input = sys.stdin.readline

start_time = time.time()
N, K = map(int, input().split())
S = list(map(int, input().split()))

start, end, flag = 0, 0, 0
ans, ans_tmp = 0, 0

while start <= N-1 and end <= N-1:
    if flag < K+1: # 홀수 개수가 maximum을 넘지 않았을 경우 다음 step으로 이동
        if S[end]%2 == 0: ans_tmp += 1
        else: flag += 1
        end += 1

        ans = max(ans, ans_tmp)
    else: # 홀수 개수가 maximum일 경우 시작 index를 한 칸씩 움직이며 홀수를 제거
        if S[start]%2 == 0: ans_tmp -= 1
        else: flag -= 1
        start += 1

print(max(ans, ans_tmp))