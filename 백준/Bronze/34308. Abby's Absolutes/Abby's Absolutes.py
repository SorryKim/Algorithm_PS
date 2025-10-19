N, K = map(int, input().split())
wants = list(map(int, input().split()))
result = []

for x in wants:
    if abs(x - N) < abs(x - 1):
        result.append(N)
    else:
        result.append(1)

print(*result)
