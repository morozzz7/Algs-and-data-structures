def tree_count(days, a, k, b, m, x):
    total_trees = a * (days - days // k) + b * (days - days // m)
    return total_trees >= x


a, k, b, m, x = map(int, input().split())

left = 0
right = x

while left < right:
    mid = (left + right) // 2
    if tree_count(mid, a, k, b, m, x):
        right = mid
    else:
        left = mid + 1

print(left)
