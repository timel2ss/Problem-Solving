import sys
from collections import deque

dx = [1, 1, -1, -1, 2, 2, -2, -2]
dy = [2, -2, 2, -2, 1, -1, 1, -1]


def bfs(sx, sy, ex, ey):
    queue = deque()
    matrix[sx][sy] = 0
    queue.append((sx, sy))

    while len(queue) != 0:
        x, y = queue.popleft()

        if x == ex and y == ey:
            print(matrix[x][y])
            return

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < w and 0 <= ny < w and matrix[nx][ny] == -1:
                matrix[nx][ny] = matrix[x][y] + 1
                queue.append((nx, ny))


T = int(sys.stdin.readline())

for _ in range(T):
    w = int(sys.stdin.readline())
    matrix = [[-1] * w for _ in range(w)]

    s_x, s_y = map(int, sys.stdin.readline().split())
    d_x, d_y = map(int, sys.stdin.readline().split())

    bfs(s_x, s_y, d_x, d_y)
