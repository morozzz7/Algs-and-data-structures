import heapq

n = int(input())
nums = list(map(int, input().split()))
heapq.heapify(nums)
total = 0

while len(nums) > 1:
    a = heapq.heappop(nums)
    b = heapq.heappop(nums)
    s = a + b
    total += s * 0.05
    heapq.heappush(nums, s)

print(total)

