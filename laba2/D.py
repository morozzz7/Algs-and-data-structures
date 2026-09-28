def f(x, a, b, c, d):
    return a * x**3 + b * x**2 + c * x + d

def find_root(a, b, c, d):
    left = -1000
    right = 1000

    for _ in range(100):
        mid = (right + left) / 2
        if f(left, a, b, c, d) * f(mid, a, b, c, d) > 0:
            left = mid
        else:
            right = mid

    return left


a, b, c, d = map(int, input().split())
x = find_root(a, b, c, d)
print(f'{x:.9f}')
