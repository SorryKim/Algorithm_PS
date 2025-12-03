from itertools import permutations

def is_valid_hour(x):
    return 1 <= x <= 12

def is_valid_minsec(x):
    return 0 <= x <= 59

A = input().strip()
h1, h2, h3 = map(int, A.split(":"))

vals = [h1, h2, h3]
cnt = 0

# (posH, posM, posS) = permutation of indices (0,1,2)
for hour_idx, min_idx, sec_idx in permutations([0, 1, 2]):
    hour = vals[hour_idx]
    minute = vals[min_idx]
    second = vals[sec_idx]

    if is_valid_hour(hour) and is_valid_minsec(minute) and is_valid_minsec(second):
        cnt += 1

print(cnt)