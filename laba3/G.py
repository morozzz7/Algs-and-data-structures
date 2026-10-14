from collections import deque

n = int(input())
arr = list(map(int, input().split()))
dq = deque()

next = 1
i = 0
while i < n or dq:
    if dq and dq[-1] == next:
        dq.pop()
        next += 1
    elif i < n:
        dq.append(arr[i])
        i += 1
    else:
        break

if next == n + 1:
    print('YES')
else:
    print('NO')
