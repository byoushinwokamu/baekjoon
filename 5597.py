import sys

arr = [0] * 31
for i in range(0, 28):
    arr[int(sys.stdin.readline())] = 1
for i in range(1, 31):
    if arr[i] == 0:
        print(i)
