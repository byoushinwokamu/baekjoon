import sys

n, m = map(int, sys.stdin.readline().split())
A = [[0 for i in range(0, m)] for j in range(0, n)]
B = [[0 for i in range(0, m)] for j in range(0, n)]

for i in range(0, n):
    A[i] = list(map(int, sys.stdin.readline().split()))
for i in range(0, n):
    B[i] = list(map(int, sys.stdin.readline().split()))

for i in range(0, n):
    for j in range(0, m):
        print(A[i][j] + B[i][j], end=" ")
    print()
