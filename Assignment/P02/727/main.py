import sys

n = input()
for i in range(int(n)):
    temp = input()
    stack = []
    for p 
    if temp != '(' or temp != ')' or temp != '+' or temp != '-' or temp != '*' or temp != '/':
        print(temp, end = '')
        temp = input()
        if temp == "\n":
            break
    else:
        if temp == '(':
            stack.append(temp)
            temp = input()
        if temp == ')':
            a = -2
            while stack[a] != '(':
                b = a+1
                print(stack[b])
                stack.pop()
                a--;
            stack.pop()
