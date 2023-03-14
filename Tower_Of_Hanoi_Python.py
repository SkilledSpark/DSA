def hanoi(n, source, target, auxiliary):
    # Base Case
    if n == 0:
        return
    elif n == 1:
        target.append(source.pop())
    
    # Recursive Case
    else:
        hanoi(n-1, source, auxiliary, target)
        target.append(source.pop())
        hanoi(n-1, auxiliary, target, source)

# Implementation using lists
l1 = [1,2,3,4,5]
l2 = []
l3 = []
print("Before: ", l1, l2, l3)
hanoi(len(l1), l1, l3, l2)
print("After: ", l1, l2, l3)