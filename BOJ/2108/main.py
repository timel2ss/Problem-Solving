import sys
from collections import Counter

if __name__ == "__main__":
  arr = []
  arrLength = int(sys.stdin.readline())
  arrSum = 0
  for i in range(arrLength):
    num = int(sys.stdin.readline())
    arr.append(num)
    arrSum += num
  arr = sorted(arr)
  print(round(arrSum / arrLength))
  print(arr[arrLength // 2])
  
  modeDict = Counter(arr)
  modes = modeDict.most_common()
  if arrLength > 1:
    if modes[0][1] == modes[1][1]:
      mode = modes[1][0]
    else:
      mode = modes[0][0]
  else:
    mode = modes[0][0]
  print(mode)
  print(arr[-1] - arr[0])