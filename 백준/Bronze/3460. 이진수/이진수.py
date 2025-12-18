import sys

T = int(sys.stdin.readline().strip())
for _ in range(T):
    n = int(sys.stdin.readline().strip())
    pos = []
    i = 0
    while n > 0:
        if n & 1:
            pos.append(i)
        n >>= 1
        i += 1
    print(*pos)
