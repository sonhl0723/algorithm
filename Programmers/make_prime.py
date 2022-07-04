from itertools import combinations
import math

def check_prime(x):
    flag = True
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            flag = False
            break
            
    return flag

def solution(nums):
    answer = 0
    
    for case in list(combinations(nums, 3)):
        if check_prime(sum(case)): answer += 1

    return answer

print(solution([1,2,7,6,4]))