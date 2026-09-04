n = int(input("Input count of array elements: "))
while True:
    arr = list(map(int, input(f"Input {n} numbers: ").split()))
    if len(arr) == n:
        break
    else:
        print(f'Error! Count of numbers must be {n}')


def quickSort(arr):
    if len(arr) <= 1:
        return arr
    left = []
    right = []
    pivot = arr[len(arr) // 2]
    middle = []
    for i in range(len(arr)):
        if arr[i] < pivot:
            left.append(arr[i])
        elif arr[i] == pivot:
            middle.append(arr[i])
        else:
            right.append(arr[i])
    return quickSort(left) + middle + quickSort(right)


print(quickSort(arr))