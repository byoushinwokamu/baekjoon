for _ in range(int(input())):
    s=input().split()
    i=float(s[0])
    for c in s:
        if c==s[0]:
            pass
        elif c=='@':
            i*=3
        elif c=='%':
            i+=5
        elif c=='#':
            i-=7
    print(f"%.2f"%i)
