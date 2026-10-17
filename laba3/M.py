from collections import deque

first = deque(map(int, input().split()))
second = deque(map(int, input().split()))

count = 0

while first and second:
    first_card = first.popleft()
    second_card = second.popleft()

    if (first_card > second_card and not (first_card == 9 and second_card == 0)) or (first_card == 0 and second_card == 9):
        first.append(first_card)
        first.append(second_card)

    else:
        second.append(first_card)
        second.append(second_card)

    count += 1
    if count >= 10**6:
        print('botva')
        break

if first:
    print(f'first {count}')
else:
    print(f'second {count}')

