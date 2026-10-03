def lower_bound(arr, target):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] >= target:
            right = mid
        else:
            left = mid + 1
    return left

def upper_bound(arr, target):
    left, right = 0, len(arr)
    while left < right:
        mid = (left + right) // 2
        if arr[mid] > target:
            right = mid
        else:
            left = mid + 1
    return left

n = int(input())
first_arr = list(map(int, input().split()))
m = int(input())
second_arr = list(map(int, input().split()))

first_arr.sort()

result = []
for x in second_arr:
    lb = lower_bound(first_arr, x)
    ub = upper_bound(first_arr, x)
    result.append(ub - lb)

print(*(result))
