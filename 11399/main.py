import sys
num = int(sys.stdin.readline())
arr = map(int, sys.stdin.readline().split(" "))
waitTime = 0
res = 0;
arr = sorted(arr)

for i in arr:
  res += i
  waitTime += res

print(waitTime)