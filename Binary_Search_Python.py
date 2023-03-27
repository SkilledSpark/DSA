main_list = [1,2,3,4,5,6,7,8,9,10]
target = int(input("Type the target number: "))

# Binary Search using Recursion
def binary_recursive(l1, n, low=0, high=None):
    # Including the default high
    if high is None:
        high = len(l1) - 1
    # Base case
    if low>high:
        return "Target not found"
    # Recursive case
    else:
        mid = (low + high) // 2
        # Best case
        if l1[mid] == n:
            return "Target found at {}".format(mid)
        elif l1[mid] > n:
            # Recurse on left half of the list
            return binary_recursive(l1, n, low, mid-1)
        else:
            # Recurse on right half of the list
            return binary_recursive(l1, n, mid+1, high)
print(binary_recursive(main_list, target))

# Binary Search without Recursion
def binary_non_recursive(l1, n):
    end = len(l1)
    mid = end//2
    while mid<end:
        if l1[mid] == n:
            return "Target found at {}".format(mid)
        elif l1[mid] > n:
            # Check to the left of the list
            end = mid
            mid = mid//2
        else:
            # Check to the right of the list
            mid = (end+mid)//2
    return "Target not found"
print(binary_non_recursive(main_list, target))
