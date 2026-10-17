data = list(map(int, input().split()))
n = data[0]
a = data[1:]

stack = []
for c in a:
    if stack and stack[-1][0] == c:
        stack[-1][1] += 1
    else:
        stack.append([c, 1])

destroyed = 0

while True:
    i = next((k for k, g in enumerate(stack) if g[1] >= 3), None)
    if i is None:
        break

    destroyed += stack[i][1] 
    del stack[i]

    if 0 < i < len(stack) and stack[i - 1][0] == stack[i][0]:
        stack[i - 1][1] += stack[i][1]
        del stack[i]

print(destroyed)