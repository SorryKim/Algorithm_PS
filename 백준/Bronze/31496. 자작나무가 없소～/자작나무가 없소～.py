import sys
input = sys.stdin.readline

N, S = input().split()
N = int(N)

deleted_count = 0

for _ in range(N):
    name, cnt = input().split()
    cnt = int(cnt)
    
    # 아이템 이름을 단어 단위로 분리
    words = name.split('_')
    
    if S in words:
        deleted_count += cnt

print(deleted_count)
