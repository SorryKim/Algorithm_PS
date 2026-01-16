N = int(input().strip())
count = 0

for A in range(1, N - 1):
    if A % 2 == 1:
        continue
    for B in range(1, N - A):
        C = N - A - B
        if C < 1:
            continue
        if C >= B + 2:
            count += 1
print(count)