import sys

string = sys.stdin.readline()
while string != ".\n":
    flag = True
    stack = []
    stack.append(" ")
    for i in range(len(string)):
        if string[i] == "(":
            stack.append(string[i])
        if string[i] == "[":
            stack.append(string[i])
        if string[i] == ")":
            if stack[-1] == "(":
                stack.pop()
            else:
                flag = False
        if string[i] == "]":
            if stack[-1] == "[":
                stack.pop()
            else:
                flag = False
    if len(stack) == 1 and flag == True:
        print("yes")
    else:
        print("no")
    string = sys.stdin.readline()