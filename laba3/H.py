from collections import deque

n = int(input())
left = deque()
right = deque()
out = []

for _ in range(n):
    parts = input().split()
    cmd = parts[0]

    if cmd == '+':
        right.append(int(parts[1]))
    elif cmd == '*':
        right.appendleft(int(parts[1]))
    else:
        out.append(left[0])
        left.popleft()

    if len(right) > len(left):
            left.append(right.popleft())
    elif len(left) > len(right) + 1:
        right.appendleft(left.pop())

for i in out:
    print(i)  

