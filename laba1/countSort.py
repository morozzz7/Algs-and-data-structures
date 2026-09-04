arr = list(map(int, input("Введите числа: ").split()))


def countSort(arr):
    len_count = max(arr) - min(arr) + 1
    count_arr = [0] * len_count
    sorted_arr = []

    for i in arr:
        count_arr[i - min(arr)] += 1

    for i in range(len_count):
        sorted_arr.extend([(min(arr) + i)] * count_arr[i])

    return sorted_arr


print(countSort(arr))


