f = [0,1,1,2]
n = int(input())
a = 2
for i in range(3,n+1):
    a += 1
    a %= 4
    if a == 0:
        f[0] = (f[2] + f[3]) % 1000000
    elif a == 1:
        f[1] = (f[0] + f[3]) % 1000000
    elif a == 2:
        f[2] = (f[0] + f[1]) % 1000000
    else:
        f[3] = (f[1] + f[2]) % 1000000
print(f[a])
