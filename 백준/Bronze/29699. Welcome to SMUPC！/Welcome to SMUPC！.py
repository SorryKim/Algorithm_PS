def func(N):
    pattern = "WelcomeToSMUPC"
    index = (N - 1) % len(pattern)  # 0-based index
    return pattern[index]


N = int(input())
print(func(N))
