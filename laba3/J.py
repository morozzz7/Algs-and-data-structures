from collections import deque
import sys

def can_sort(arr):
    dq = deque()
    n = len(arr)
    expected = sorted(arr)
    idx = 0
    i = 0

    while i < n or dq:
        if dq and dq[-1] == expected[idx]:
            dq.pop(); idx += 1
        elif i < n and arr[i] == expected[idx]:
            i += 1; idx += 1
        elif i < n:
            dq.append(arr[i]); i += 1
        else:
            break

    return idx == n


data = sys.stdin.read().split()
pos = 0
N = int(data[pos])
pos += 1
res = []
for _ in range(N):
    K = int(data[pos]) 
    pos += 1
    raw = [float(data[pos + j]) for j in range(K)]
    pos += K


    res.append(1 if can_sort(raw) else 0)

print('\n'.join(map(str, res)))


