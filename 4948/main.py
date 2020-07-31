import sys

limit = 123456 * 2 + 1
arr = [i for i in range(limit)]
arr[0] = 0
arr[1] = 0

for i in range(2, limit):
  if(arr[i] == 0):
    continue
  else:
    for j in range(i+i, limit, i):
      arr[j] = 0

case = int(sys.stdin.readline())
while(case != 0):
  count = 0
  for i in range(case + 1, case * 2 + 1):
    if(arr[i] != 0):
      count += 1
  print(count)
  case = int(sys.stdin.readline())