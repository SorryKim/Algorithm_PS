n = input()
num = int(n)

contains_7 = '7' in n
divisible_by_7 = num % 7 == 0

if contains_7 and divisible_by_7:
    print(3)
elif not contains_7 and divisible_by_7:
    print(1)
elif contains_7 and not divisible_by_7:
    print(2)
else:
    print(0)
