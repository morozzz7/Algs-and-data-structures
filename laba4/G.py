import heapq

n = int(input())
heap = []
for i in range(n):
    a = int(input())
    heap.append((max(1000 - a, 1), i, max(1000 - a, 1)))
heapq.heapify(heap)

time = 0
pos = 0

while True:
    t, j, wait = heapq.heappop(heap)
    if time + abs(pos - j) <= t:
        time = t
        pos = j
        nw = max(wait - 1, 1)
        heapq.heappush(heap, (t + nw, j, nw))
    else:
        print(t)
        break