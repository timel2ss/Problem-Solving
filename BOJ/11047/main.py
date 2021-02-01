import sys
num, val = map(int, sys.stdin.readline().split(" "))
arr = []
count = 0

for i in range(num):
  arr.append(int(sys.stdin.readline()))

while(val != 0):
  for i in reversed(range(num)):
    if(val >= arr[i]):
      val -= arr[i]
      count += 1
      break

print(count)