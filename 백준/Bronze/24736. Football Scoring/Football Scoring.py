def calculate(t, f, s, p, c):
    return t * 6 + f * 3 + s * 2 + p * 1 + c * 2
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a_score = calculate(*a)
b_score = calculate(*b)

print(a_score, b_score)