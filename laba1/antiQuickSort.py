def anti_qs(n):
    arr = list(range(1, n + 1))
    for i in range(2, n):
        arr[i], arr[i // 2] = arr[i // 2], arr[i]
    return arr


n = int(input())
print(*anti_qs(n))