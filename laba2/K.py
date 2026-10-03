def balloons(T, t, z, y):
    cycle = z * t + y
    full = T // cycle
    res = full * z
    rem = T - full * cycle
    res += min(z, rem // t)
    return res

M, N = map(int, input().split())
h = [tuple(map(int, input().split())) for _ in range(N)]

l, r = 0, 1000000
while l < r:
    m = (l + r) // 2
    if sum(balloons(m, *x) for x in h) >= M:
        r = m
    else:
        l = m + 1

T = l

res = [0] * N
rem = M
for i in range(N):
    mx = balloons(T, *h[i])
    others = sum(balloons(T, *h[j]) for j in range(i + 1, N))
    take = min(mx, rem)
    res[i] = take
    rem -= take

print(T)
print(*res)