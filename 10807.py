import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
v = int(input())

cnt = 0
for i in range(0, n):
    if arr[i] == v:
        cnt += 1
print(cnt)
