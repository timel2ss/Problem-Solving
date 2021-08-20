import sys

N = int(sys.stdin.readline())
ropes = [int(sys.stdin.readline()) for _ in range(N)]
ropes.sort()

temp = -1
for i in range(N):
    rope_w = ropes[i] * (N - i)
    if temp < rope_w:
        temp = rope_w
print(temp)