t1, e1, f1 = map(int, input().split())
t2, e2, f2 = map(int, input().split())
# 총 시청 시간 계산 (트레일러: 3분, 시리즈: 20분, 영화: 120분)
time1 = t1 * 3 + e1 * 20 + f1 * 120
time2 = t2 * 3 + e2 * 20 + f2 * 120

if time1 > time2:
    print("Max")
elif time1 < time2:
    print("Mel")
else:
    print("Draw")
