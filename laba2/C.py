import math

def find_root(c):
    left = 0.0
    right = c

    for _ in range(100):
        mid = (right + left) / 2
        val = mid**2 + math.sqrt(mid)

        if val < c:
            left = mid
        else:
            right = mid

    return left


c = float(input())
x = find_root(c)
print(f'{x:.9f}')
