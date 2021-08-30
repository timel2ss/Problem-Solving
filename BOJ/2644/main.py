import sys
from collections import deque


def bfs(s, d):
    queue = deque()
    queue.append((s, 0))

    while queue:
        node, count = queue.popleft()
        if node == d:
            return count

        visited[node] = True

        for relation in relations[node]:
            if not visited[relation]:
                queue.append((relation, count + 1))
    return -1


n = int(sys.stdin.readline())
relations = [[] for _ in range(n + 1)]

p1, p2 = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
for _ in range(m):
    parent, child = map(int, sys.stdin.readline().split())
    relations[child].append(parent)
    relations[parent].append(child)

visited = [False for _ in range(n + 1)]
print(bfs(p1, p2))
