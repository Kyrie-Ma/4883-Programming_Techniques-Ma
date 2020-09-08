import sys

n = input()
for i in range(int(n)):
    temp = input()
    if temp != '(' or temp != ')' or temp != '+' or temp != '-' or temp != '*' or temp != '/':
        print(temp, end = '')
    else:
        if