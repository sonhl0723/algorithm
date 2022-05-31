# -*- coding: utf-8 -*-
# 1부터 N까지의 합은 (N*(N+1))/2
# (N*(N+1))/2가 S보다 작을 때까지 본다.

S = int(input())

ans = 0
start = 1
end = S

while start <= end:
    mid = (start+end)//2
    
    if (mid*(mid+1))/2 <= S:
        ans = mid
        start = mid+1
    else:
        end = mid-1

print(ans)