arr = list(map(int, input("Введите числа: ").split()))


def SelectionSort(arr):
    for i in range(len(arr) - 1):
        max_ind = i
        for j in range(i + 1, len(arr)):
            if arr[j] > arr[max_ind]:
                max_ind = j
        arr[i], arr[max_ind] = arr[max_ind], arr[i]

    return arr


print(SelectionSort(arr))
