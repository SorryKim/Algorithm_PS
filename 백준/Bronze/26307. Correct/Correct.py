H, M = map(int, input().split())

START_H = 9
START_M = 0
answer = (H - START_H) * 60 + (M - START_M)
print(answer)