# -*- coding: utf-8 -*-
# 제한 시간이 2초이고 최대 정점의 개수가 500개 이기 때문에 폴로이드 알고리즘으로도 풀이 가능
# 1. 폴로이드 알고리즘
# 삼중 for문을 돌며 최소값으로 map_을 채움
# 최종 map_의 cost와 요청한 cost를 비교하여 답을 출력
# => 시간 초과, 파이썬이라 시간 제한이 걸린다고 판단, C++이었으면 됐을듯
# 2. 다익스트라 알고리즘
# 

import sys

N, M = map(int, sys.stdin.readline().split())

#################### 플로이드 알고리즘
# map_ = []

# for _ in range(N): map_.append(list(map(int, sys.stdin.readline().split())))

# for k in range(N):
#     for i in range(N):
#         for j in range(N):
#             if map_[i][j] == 0: map_[i][j] = 1000000001
            
#             if (map_[i][k] + map_[k][j]) < map_[i][j]: map_[i][j] = (map_[i][k] + map_[k][j])

# for idx in range(M):
#     i, j, cost = map(int, sys.stdin.readline().split())

#     if map_[i-1][j-1] <= cost: print("Enjoy other party")
#     else: print("Stay here")

#################### 다익스트라 알고리즘
