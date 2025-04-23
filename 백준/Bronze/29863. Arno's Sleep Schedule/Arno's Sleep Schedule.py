sleep_time = int(input())
alarm_time = int(input())
if sleep_time <= alarm_time:
    ans = alarm_time - sleep_time
else:
    ans = 24 - sleep_time + alarm_time
print(ans)