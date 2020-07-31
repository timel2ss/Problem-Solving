import sys

M = int(sys.stdin.readline())
N = int(sys.stdin.readline())

arr = [i for i in range(N + 1)]
arr[0] = 0
arr[1] = 0

for num in range(2, N + 1):
  if(arr[num] == 0):
    continue
  else:
    for numX2 in range(num + num, N + 1, num):
      arr[numX2] = 0

flag = 0
total = 0
for i in range(M, N+1):
  if(arr[i] != 0):
    flag += 1
  if(flag == 1):
    least = arr[i]
    flag += 1
  total += arr[i]

if(total > 0):
  print(total)

if(flag == 0):
  print(-1)
else:
  print(least)