for t in range(3):
    a = int(input())
    res = 0
    for i in range(a):
        res += int(input())
    if res == 0:
        print("0")
    elif res > 0:
        print('+')
    else:
        print('-')
