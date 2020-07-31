import sys
M, N = map(int, sys.stdin.readline().split(" "))

arr = [i for i in range(N+1)]
arr[0] = 0
arr[1] = 0

for i in range(2, N+1):
  if(arr[i] == 0):
    continue
  else:
    for j in range(i + i, N+1, i):
      arr[j] = 0

for i in range(M, N+1):
  if(arr[i] != 0):
    print(i)