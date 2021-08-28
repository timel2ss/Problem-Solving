import sys
sys.setrecursionlimit(100000)


def dfs(s):
    for node in arr[s]:
        if parents[node] == 0:
            parents[node] = s
            dfs(node)


N = int(sys.stdin.readline())
arr = [[] for _ in range(N + 1)]

for i in range(N - 1):
    node1, node2 = map(int, sys.stdin.readline().split())
    arr[node1].append(node2)
    arr[node2].append(node1)


parents = [0 for _ in range(N + 1)]
dfs(1)

for i in range(2, N + 1):
    print(parents[i])
