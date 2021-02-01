import sys

def star(arr, i, j, n):
  if n == 1:
    arr[i][j] = "*"
  else:
    for x in range(3):
      for y in range(3):
        if x != 1 or y != 1:
          star(arr, i+(n//3)*x, j+(n//3)*y, n//3)

if __name__ == "__main__":
  num = int(sys.stdin.readline())
  arr = [[" "] * num for _ in range(num)]
  star(arr, 0, 0, num)
  for i in range(num):
    for j in range(num):
      print(arr[i][j], end="")
    print()