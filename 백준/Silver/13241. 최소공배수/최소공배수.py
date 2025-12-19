import math
import sys

def solve():

    try:
        line = sys.stdin.readline()
        if not line:
            return
        a, b = map(int, line.split())
        gcd_val = math.gcd(a, b)
        lcm_val = (a * b) // gcd_val
        print(lcm_val)
    except EOFError:
        pass

if __name__ == "__main__":
    solve()