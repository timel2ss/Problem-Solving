import sys

T = int(sys.stdin.readline())
for i in range(T):
    count = 1
    N = int(sys.stdin.readline())
    ranks = sorted([tuple(map(int, sys.stdin.readline().split())) for _ in range(N)], key=lambda x: x[0])

    top = ranks[0][1]
    for j in range(1, N):
        if top > ranks[j][1]:
            count += 1
            top = ranks[j][1]
    print(count)