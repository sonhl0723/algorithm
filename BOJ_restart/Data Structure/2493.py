# -*- coding: utf-8 -*-
# 입력받은 리스트에서 각 요소들의 왼쪽 방향으로 값이 더 큰 가장 가까운 인덱스를 출력
# --- 풀이 1
# 오른쪽에서 시작하여 고려하고 있는 값보다 더 큰 가장 가까운 인덱스를 찾아 answer 리스트에 값을 추가
# -> 시간초과, 내 예상으로는 매번 리스트를 복사했기 때문에 시간초과가 발생해
# --- 풀이 2
# 입력받은 리스트를 deque로 선언하고 또 하나의 deque를 선언하여 pop / append / extend를 사용하여 시간복잡도를 최대한 줄인다.
# ->  시간초과
# --- 풀이 3
# input 스택, 참조 스택 총 2개의 스택 생성
# 오른쪽에 있는 요소들부터 확인하며 왼쪽의 값보다 크다면 참조 스택에 append
# input 스택의 가장 오른쪽에 있는 값에 대해 참조 스택의 top부터 확인하며 참조 스택의 top이 해당 값보다 작거나 같으면 input 스택의 인덱스 값을 top의 ans에 설정
# 참조 스택에 있는 값들의 순서는 앞에 있는 값보다 큰 값이기 때문에 앞의 값들에서 조건에 걸린다면 다음을 보지 않고 바로 break

import sys
from collections import deque

N = int(input())
top_list = deque(map(int, sys.stdin.readline().split()))
ans = [0]*N
stack = deque([])

while top_list:
    curr = top_list.pop()
    N -= 1
    
    while stack:
        tmp = stack.pop()
        if tmp[0] <= curr: ans[tmp[1]] = N+1
        else:
            stack.append(tmp)
            break
    
    stack.append([curr, N])

print(*list(ans))