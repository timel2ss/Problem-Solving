import sys

def find(arr, operand):
  idx = operand
  while(arr[idx] != idx):
    idx = arr[idx]
  return idx

def union(arr, operand1, operand2):
  op1 = find(arr, operand1)
  op2 = find(arr, operand2)
  if(op1 != op2):
    arr[op2] = op1

if __name__ == "__main__":
  setNum, opNum = map(int, sys.stdin.readline().split(" "))

  arr = [i for i in range(setNum + 1)]

  for i in range(opNum):
    op, operand1, operand2 = map(int, sys.stdin.readline().split(" "))
    if op == 0:
      union(arr, operand1, operand2)
    elif op == 1:
      if find(arr, operand1) == find(arr, operand2):
        print("YES")
      else:
        print("NO")