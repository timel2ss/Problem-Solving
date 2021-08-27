import sys
sys.setrecursionlimit(100000)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dfs(x, y, h):
    visited[x][y] = True

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < N and heights[nx][ny] > h and not visited[nx][ny]:
            dfs(nx, ny, h)


N = int(sys.stdin.readline())
heights = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
result = 1

for height in range(1, max(map(max, heights)) + 1):
    cnt = 0
    visited = [[False] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if heights[i][j] > height and not visited[i][j]:
                dfs(i, j, height)
                cnt += 1

    result = max(result, cnt)

print(result)
