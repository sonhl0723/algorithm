import sys

N, M = map(int, sys.stdin.readline().split())

ans = []

def dfs(start):
    global ans, N, M

    if len(ans) == M:
        print(ans)
        return

    for idx in range(start, N+1):
        ans.append(idx)
        dfs(idx)
        ans.pop()

dfs(1)