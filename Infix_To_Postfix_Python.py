# Infix to Postfix expression using Python

expression = input("Type the Infix expression: ")
queue = []
operators = {"^": 3, "*": 2, "/": 2, "+": 1, "-": 1}
stack = []

for i in expression:
    # Check for the operand
    if i.isalnum():
        queue.append(i)
    
    # Check for the parenthesis
    elif i == "(":
        stack.append(i)
    elif i == ")":
        while stack and stack[-1] != "(":
            queue.append(stack.pop())
        stack.pop()
    # Check for the order of precedence of the operators
    elif i in operators:
        while stack and stack[-1] != "(" and operators[i] <= operators[stack[-1]]:
            queue.append(stack.pop())
        stack.append(i)

while stack:
    queue.append(stack.pop())
print("Postfix Expression:", "".join(queue))
