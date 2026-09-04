arr = list(map(int, input("Введите числа: ").split()))


def BubbleSort(arr):
    for i in range(len(arr) - 1):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] < arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break
    return arr


print(BubbleSort(arr))
