import sys

if __name__ == "__main__":
  input_str = sys.stdin.readline()[:-1].split('-')
  res = 0
  for i in range(len(input_str)):
    temp = list(map(int, input_str[i].split('+')))
    val = 0
    for j in range(len(temp)):
      val += temp[j]
    if i == 0:
      res += val
    else:
      res -= val
  print(res)