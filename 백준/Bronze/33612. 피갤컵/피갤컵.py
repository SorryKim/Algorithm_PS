N = int(input())

base_year = 2024
base_month = 8

total_months = (N - 1) * 7

new_month = base_month + total_months
year = base_year + (new_month - 1) // 12 
month = (new_month - 1) % 12 + 1          

print(year, month)