import sys

N = int(sys.stdin.readline())

dp = [0] * (N + 5)
dp[1] = 1
dp[2] = 1

for i in range(3, N + 1):
    dp[i] = dp[i - 2] * 2 + dp[i - 3]

print(dp[N])
