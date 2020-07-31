import sys
n = int(sys.stdin.readline())
arr = [0, 1]
for i in range(2, n + 1):
  arr.append(arr[i - 1] + arr[i - 2])
print(arr[n])
