# -*- coding: utf-8 -*- 

# LIFO로 '('를 리스트에 추가하고 ')'가 입력으로 들어올 때마다 리스트의 요소를 하나씩 제거하는 것
# append로 원소를 추가하고 pop을 하게 되면 시간복잡도는 O(1)이 된다.

import sys

N = int(input())
mylist = []

for _ in range(N):
    myinput = sys.stdin.readline().rstrip()
    flag = False
    for ch in myinput:
        if ch =='(': mylist.append(ch)
        else:
            if mylist: mylist.pop()
            else:
                flag = True
                break
    
    if flag: print("NO")
    else:
        if len(mylist)==0: print("YES")
        else: print("NO")

    if len(mylist)!=0: mylist.clear()
