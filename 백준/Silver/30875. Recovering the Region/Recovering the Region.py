N = int(input())

answer = [[1]*N for _ in range(N)]

for x in range(1,N,2):
    for y in range(N):
        answer[x][y] = 2

for row in answer:
    print(" ".join(map(str, row)))