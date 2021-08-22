import sys
import heapq

N = int(sys.stdin.readline())
bunches = [int(sys.stdin.readline().rstrip()) for _ in range(N)]
heapq.heapify(bunches)

result = 0
while len(bunches) > 1:
    bunch1 = heapq.heappop(bunches)
    bunch2 = heapq.heappop(bunches)
    temp = bunch1 + bunch2
    heapq.heappush(bunches, temp)
    result += temp

print(result)