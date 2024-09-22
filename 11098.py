for t in range(int(input())):
    mc = 0
    na = ""
    for i in range(int(input())):
        nc, nn = input().split()
        nc = int(nc)
        if mc < nc:
            mc, na = nc, nn
        else:
            input()
    print(na)
