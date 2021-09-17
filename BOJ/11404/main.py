import sys

INF = int(1e9)
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

busInfos = [[INF] * (n + 1) for _ in range(n + 1)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    busInfos[a][b] = min(busInfos[a][b], c)

for k in range(1, n + 1):
    busInfos[k][k] = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            busInfos[i][j] = min(busInfos[i][j], busInfos[i][k] + busInfos[k][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if busInfos[i][j] == INF:
            print(0, end=" ")
        else:
            print(busInfos[i][j], end=" ")
    print()
