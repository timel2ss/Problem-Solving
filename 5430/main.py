import sys
from collections import deque

if __name__ == "__main__":
  for i in range(int(sys.stdin.readline())):
    flag = True
    count = 0
    commands = sys.stdin.readline()
    commands = list(commands)

    arrLength = int(sys.stdin.readline())

    if arrLength != 0:
      arr = list(map(int, sys.stdin.readline()[1:-2].split(",")))
      arr = deque(arr)
    else:
      temp = sys.stdin.readline()
      arr = deque()

    for command in commands:
      if command == 'R':
        count += 1
      elif command == 'D':
        if arrLength <= 0:
          flag = False
        else:
          if count % 2 == 0:
            arr.popleft()
            arrLength -= 1
          else:
            arr.pop()
            arrLength -= 1

    if flag == True:
      if arrLength != 0:
        if count % 2 != 0:
          arr.reverse()
        print("[" + str(arr[0]), end="")
        for i in range(1, arrLength):
          print("," + str(arr[i]), end="")
        print("]")
      else:
        print("[]")
    else:
      print("error")