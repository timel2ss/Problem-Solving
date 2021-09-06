import sys
from collections import deque


def bfs(sx, sy):
    max_val = -1

    visited = [[-1] * width for _ in range(height)]
    visited[sx][sy] = 0

    queue = deque()
    queue.append((sx, sy))
    while queue:
        x, y = queue.popleft()
        max_val = max(max_val, visited[x][y])

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < height and 0 <= ny < width and visited[nx][ny] == -1 and treasure_map[nx][ny] == 'L':
                visited[nx][ny] = visited[x][y] + 1
                queue.append((nx, ny))
    return max_val


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

height, width = map(int, sys.stdin.readline().split())
treasure_map = [sys.stdin.readline().rstrip() for _ in range(height)]

result = -1
for i in range(height):
    for j in range(width):
        if treasure_map[i][j] == 'L':
            result = max(result, bfs(i, j))

print(result)
