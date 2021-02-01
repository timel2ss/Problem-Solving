import sys

def tile(arr, num):
  for i in range(2, num+1):
    arr[i] = ((arr[i - 1] % 15746) + (arr[i - 2] % 15746)) % 15746
  return arr[num]

if __name__ == "__main__":
  num = int(sys.stdin.readline())
  arr = [1 for _ in range(num + 1)]
  print(tile(arr, num))