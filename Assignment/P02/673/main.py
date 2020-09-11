n = input()
for i in range(int(n)):
  parentheses = input()
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
        temp = "No"
        break
      if p == ')':
        if myStack[-1] == '(':
          myStack.pop()
        else:
          temp = "No"
          break
      if p == ']':
        if myStack[-1] == '[':
          myStack.pop()
        else:
          temp = "No"
          break
  if len(myStack) > 0:
    temp = "No"
  myStack = []
  print(temp)
