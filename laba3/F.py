from collections import deque

n, k = map(int, input().split())
arr = list(map(int, input().split()))
dq = deque()
result = []

for i in range(n):
    while dq and arr[dq[-1]] >= arr[i]:
        dq.pop()
    dq.append(i)
    if dq[0] < i - k + 1:
        dq.popleft()

    if i >= k - 1:
        print(arr[dq[0]])


