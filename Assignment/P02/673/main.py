import sys

n = input()
#f = open("infile.txt", "r")
#n = int(f.readline())
for i in range(int(n)):
    parentheses = input()
    #parentheses = f.readline().strip()

    if len(parentheses) % 2 == 1:
        print("No")
        continue

    myStack = []

    temp = "Yes"
    for p in parentheses:
        if p == '(' or p == '[':
            myStack.append(p)
        else:
            if len(myStack) == 0:
                #print("No")
                temp = "No"
                break
            if p == ')':
                if myStack[-1] == '(':
                    myStack.pop()
                else:
                    #print("No")
                    temp = "No"
                    break
            if p == ']':
                if myStack[-1] == '[':
                    myStack.pop()
                else:
                    #print("No")
                    temp = "No"
                    break
    if len(myStack) > 0:
        print("No")
    print(temp)