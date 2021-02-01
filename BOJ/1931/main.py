import sys

def greedy(meeting):
  count = 0;
  startTime = 0;

  for time in meeting:
    if time[0] >= startTime:
      startTime = time[1]
      count += 1
  return count

num = int(sys.stdin.readline())
meeting = []
for i in range(num):
  start, end = map(int, sys.stdin.readline().split(" "))
  meeting.append((start, end))

meeting = sorted(meeting, key = lambda time: time[0])
meeting = sorted(meeting, key = lambda time: time[1])
print(greedy(meeting))