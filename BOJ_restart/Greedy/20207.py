# -*- coding: utf-8 -*-
# 범위 안의 값을 구하는 문제이기 때문에 인덱스를 기준으로 그리디
# 시작일을 기준으로 데이터를 정렬

import sys

input = sys.stdin.readline
N = int(input())
days = []
for _ in range(N): days.append(list(map(int, input().split())))

days.sort(key = lambda x:x[0])

row_list = []
_min, _max = -1, -1
col, row, ans = 0, 1, 0

for idx in range(len(days)):

    if _min == -1:
        _min, _max = days[idx][0], days[idx][1]
        col = _max-_min+1
        row_list.append(_max)
    else:
        cur_s, cur_e = days[idx][0], days[idx][1]
        flag = False

        # 시작일수가 update되지 않는 경우
        if cur_s >= _min and cur_s <= _max+1:
            # row 계산
            for _idx in range(len(row_list)):
                if row_list[_idx] < cur_s:
                    row_list[_idx] = cur_e
                    flag = True
                    break
            if not flag:
                row_list.append(cur_e)
                row += 1

            # col 계산
            if cur_e <= _max: pass
            else:
                col += (cur_e-_max)
                _max = cur_e

        # 시작일수가 update되는 경우
        else:
            row_list = [cur_e]
            ans += col*row
            col, row = (cur_e-cur_s+1), 1
            _min, _max = cur_s, cur_e

    if idx == len(days)-1:
        ans += col*row

print(ans)