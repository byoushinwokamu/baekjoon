import sys

n, x = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

for i in range(0, n):
    if arr[i] < x:
        print(arr[i])
