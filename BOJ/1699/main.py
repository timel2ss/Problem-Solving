import sys

N = int(sys.stdin.readline())
dp = [x for x in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, i):
        if j * j > i:
            break
        dp[i] = min(dp[i], dp[i-j*j] + 1)

print(dp[N])
