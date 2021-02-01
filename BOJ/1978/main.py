import sys

def primeNumber(x):
  if x == 1:
    return 0
  count = 0
  for i in range(2, x + 1):
    if(x % i == 0):
      count += 1
  if count == 1:
    return 1
  else:
    return 0

num = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split(" ")))
count = 0

for i in arr:
  count += primeNumber(i)

print(count)