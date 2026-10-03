n, r, c = map(int, input().split())
heights = []
for h in range(n):
    h = int(input())
    heights.append(h)

heights.sort()

left = 0
right = heights[-1] - heights[0]

while left < right:
    mid = (left + right) // 2
    count = 0
    i = 0
    while i + c <= n:
        if heights[i + c - 1] - heights[i] <= mid:
            count += 1
            i += c
        else:
            i += 1
        if count == r:
            break

    if count == r:
        right = mid
    else:
        left = mid + 1

print(left)



