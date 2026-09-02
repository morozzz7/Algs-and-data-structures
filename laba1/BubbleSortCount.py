arr = list(map(int, input("Введите числа: ").split()))


def BubbleSort(arr):
    count = 0
    for i in range(len(arr) - 1):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
                count += 1
            print(arr)

        if not swapped:
            break
    return count


print(BubbleSort(arr))
