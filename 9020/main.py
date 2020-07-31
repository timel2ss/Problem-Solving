import sys

limit = 10001
arr = [i for i in range(limit)]
arr[0] = 0
arr[1] = 0

for i in range(2, limit):
  if(arr[i] == 0):
    continue
  else:
    for j in range(i + i, limit, i):
      arr[j] = 0

cases = int(sys.stdin.readline())

for _ in range(cases):
  case = []
  num = int(sys.stdin.readline())
  middle = num // 2
  i = j = middle
  for __ in range(middle):
    if(arr[i] == 0):
      i -= 1
    if(arr[j] == 0):
      j += 1
    if(arr[i] + arr[j] == num):
      print(i, j)
      break
    else:
      i -= 1
      j += 1