import heapq

n = int(input())
ranges = []
heap = []
answer = 0

for _ in range(n):
    arr_t, serv_t = map(int, input().split())
    ranges.append((arr_t, serv_t))
ranges.sort()

for T in ranges:
    while heap and heap[0] <= T[0]:
        heapq.heappop(heap)
    heapq.heappush(heap, sum(T))
    answer = max(answer, len(heap))

print(answer)
    
