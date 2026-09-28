import sys

def binarySearh(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        guess = arr[mid]

        if guess == target:
            return 1

        if guess < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1


n, k = map(int, input().split())

n_lst = list(map(int, input().split()))
k_lst = list(map(int, input().split()))

if len(n_lst) != n or len(k_lst) != k:
    print('Длина списка должна совпадать с введенным необходимым числом элементов')
    sys.exit()

for i in k_lst:
    if binarySearh(n_lst, i) == 1:
        print('YES')
    else:
        print('NO')
    


