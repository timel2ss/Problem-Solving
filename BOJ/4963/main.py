import sys

dx = [1, -1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


def dfs(x, y):
    visited[x][y] = True

    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue

        if matrix[nx][ny] == 1 and (not visited[nx][ny]):
            dfs(nx, ny)


result = 0

while True:
    w, h = map(int, sys.stdin.readline().split())

    if w == 0 and h == 0:
        break

    result = 0
    matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    visited = [[False] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if matrix[i][j] == 1 and (not visited[i][j]):
                dfs(i, j)
                result += 1

    print(result)
