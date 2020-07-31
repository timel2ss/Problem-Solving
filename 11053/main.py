import sys
num = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split(" ")))

res = [0 for _ in range(num)]
for i in range(num):
  for j in range(i):
    if arr[i] > arr[j] and res[i] < res[j]:
      res[i] = res[j]
  res[i] += 1
  
print(max(res))