import sys

def nearestBinarySearh(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        guess = arr[mid]

        if guess == target:
            return guess

        if guess < target:
            left = mid +1
        else:
            right = mid - 1

    if left >= len(arr):
        return arr[-1]
    if right < 0: 
        return arr[0]

    if target - arr[right] <= arr[left] - target:
            return arr[right]
    return arr[left]
    
    
    

n, k = map(int, input().split())

n_lst = list(map(int, input().split()))
k_lst = list(map(int, input().split()))

if len(n_lst) != n or len(k_lst) != k:
    print('Длина списка должна совпадать с введенным необходимым числом элементов')
    sys.exit()

for i in k_lst:
    nearest = nearestBinarySearh(n_lst, i)
    print(nearest)
    


