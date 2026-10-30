import heapq
import sys

heap = []

for line in sys.stdin:
    parts = line.split()
    cmd = parts[0]

    if cmd == 'CLEAR':
        heap.clear()
    
    elif cmd == 'ADD':
        heapq.heappush(heap, -int(parts[1]))

    else:
        if heap:
            max = -(heapq.heappop(heap))
            print(max)
        else:
            print('CANNOT')


