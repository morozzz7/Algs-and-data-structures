distances = list(map(int, input().split()))
tariffs = list(map(int, input().split()))


def lowest_total(distances, tariffs):
    distances.sort(reverse=True)
    tariffs.sort()

    total = sum(d * t for d, t in zip(distances, tariffs))
    return total


print(lowest_total(distances, tariffs))