import sys

n = input()
for i in range(int(n)):
    temp = input()
    temp = input()
    stack = []
    if temp != '(' or temp != ')' or temp != '+' or temp != '-' or temp != '*' or temp != '/':
        print(temp, end = '')
        temp = input()
        if temp == "\n":
            break
    else:
        if temp == '(':
            stack.append(temp)
            temp = input()
            if temp == '\n':
                break
        if temp == ')':
            a = -2
            while stack[a] != '(':
                b = a+1
                print(stack[b])
                temp2 = stack.pop()
                print(temp2, end = '')
                a = a-1
            stack.pop()
            temp = input()
            if temp == '\n':
                break
        if temp == '*':
            stack.append(temp)
            temp = input()
            if temp =='\n':
                break
        if temp == '/':
            stack.append(temp)
            temp = input()
            if temp == '\n':
                break
        if temp == '+':
            if stack[-1] == '*' or stack[-1] == '/':
                c = -2
                while stack[c] !='(':
                    temp2 = stack.pop()
                    print(temp2, end = '')
            stack.append(temp)
            temp = input()
            if temp == '\n':
                break
        if temp == '-':
            if stack[-1] == '*' or stack[-1] == '/':
                c = -2
                while stack[c] !='(':
                    temp2 = stack.pop()
                    print(temp2, end = '')
            stack.append(temp)
            temp = input()
            if temp == '\n':
                while stack.size() != 0:
                    temp2 = stack.pop()
                    print(temp2, end = '')
                break