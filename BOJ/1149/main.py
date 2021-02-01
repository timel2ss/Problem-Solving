import sys

arr = []
num = int(sys.stdin.readline())

for i in range(num):
  arr.append(list(map(int, sys.stdin.readline().split(" "))))

for i in range(1, num):
  arr[i][0] = arr[i][0] + min(arr[i-1][1], arr[i-1][2])
  arr[i][1] = arr[i][1] + min(arr[i-1][0], arr[i-1][2])
  arr[i][2] = arr[i][2] + min(arr[i-1][0], arr[i-1][1])

print(min(arr[num-1]))