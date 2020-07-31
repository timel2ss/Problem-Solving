import sys

x = []
y = []

for i in range(3):
 pointX, pointY = map(int, sys.stdin.readline().split(" "))
 x.append(pointX)
 y.append(pointY)

for i in range(3):
  if x.count(x[i]) == 1:
    x_res = x[i]
  if y.count(y[i]) == 1:
    y_res = y[i]

print(x_res, y_res)