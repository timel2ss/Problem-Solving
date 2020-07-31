import sys

if __name__ == "__main__":
  num = int(sys.stdin.readline())
  stack = []
  stackPrint = []
  
  count = 1
  flag = False
  for i in range(num):
    n = int(sys.stdin.readline())
    while count <= n:
      stack.append(count)
      stackPrint.append("+")
      count += 1
    if stack[-1] == n:
      stack.pop()
      stackPrint.append("-")
    else:
      flag = True
  
  if(flag):
    print("NO")
  else:
    for i in stackPrint:
      print(i)
    