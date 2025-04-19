n = int(input())
a = list(map(int, input().split()))

even_count = sum(1 for x in a if x % 2 == 0)
odd_count = n - even_count

if even_count > odd_count:
    print("Happy")
else:
    print("Sad")
