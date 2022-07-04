def solution(a, b):
    return sum(_a*_b for _a, _b in zip(a, b))

print(solution([-1,0,1], [1,0,-1]))