n = int(input())
sequence = list(map(int, input().split()))
total = sum(sequence)
if total > 0:
    print("Right")
elif total < 0:
    print("Left")
else:
    print("Stay")
