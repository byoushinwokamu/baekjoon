import sys

str = ""
while True:
    try:
        str += sys.stdin.readline()
    except:
        break
print(str)
