distances = list(map(int, input('Input distances: ').split()))
tariffs = list(map(int, input('Input tariffs: ').split()))


def lowest_total(distances, tariffs):
    distances.sort(reverse=True)
    tariffs.sort()

    total = sum(d * t for d, t in zip(distances, tariffs))
    return total


print(lowest_total(distances, tariffs))