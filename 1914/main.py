import sys

def top(n, a, b, c):
  if n == 1:
    print(a, c)
  else:
    top(n-1, a, c, b)
    print(a, c)
    top(n-1, b, a, c)

num = int(sys.stdin.readline())

print(pow(2, num) - 1)
if num <= 20:
  top(num, 1, 2, 3)