import sys

N = int(input())
arr = []
q = []
white = 0
blue = 0

def recurs(arr, my_range):
    global white, blue, q

    col_start, col_end, row_start, row_end = my_range[0], my_range[1], my_range[2], my_range[3]

    tmpN = (col_end-col_start)//2
    color = arr[col_start][row_start]

    for col in range(col_start, col_end):
        for row in range(row_start, row_end):
            if arr[col][row] != color:
                q.append([col_start, col_start+tmpN, row_start, row_start+tmpN])
                q.append([col_start, col_start+tmpN, row_start+tmpN, row_end])
                q.append([col_start+tmpN, col_end, row_start, row_start+tmpN])
                q.append([col_start+tmpN, col_end, row_start+tmpN, row_end])
                return

    if color == 0: white += 1
    else: blue += 1
            
for _ in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    arr.append(tmp)

q.append([0,N,0,N])

while len(q)>0:
    recurs(arr, q.pop(0))

print(str(white))
print(str(blue))