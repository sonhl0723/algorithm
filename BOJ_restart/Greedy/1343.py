# -*- coding: utf-8 -*-
# start와 end 두 개의 포인터로 'X'의 길이를 판단한다.
# X가 연속되는 상황에서 4개가 되면 answer에 'AAAA'를 추가하고 flag를 True로 설정하면서 start와 end를 end+1값으로 설정한다.
# '.'이 나오는 상황에서 end와 start의 차이로 구별한다. end와 start의 차이가 1이라면 "BB", 차이가 3이라면 "AAAA"를 추가한다.
# 차이가 0이라면 "."을 추가하고 차이가 1,3,0이 아니면 answer를 -1로 설정한다. 

import sys

N = sys.stdin.readline().split()[0]

answer = ""

start = 0
end = 0

while end < len(N):
    if N[end] =='X':
        if end-start == 3:
            answer += "AAAA"
            end += 1
            start = end
        else: end += 1
    else:
        if end-start == 2: answer += "BB"
        elif end-start == 4: answer += "AAAA"
        elif end-start != 0:
            answer = "-1"
            break

        answer += "."
        end += 1
        start = end

if end-start == 2: answer += "BB"
elif end-start == 4: answer += "AAAA"
elif end-start != 0: answer = "-1"

print(answer)