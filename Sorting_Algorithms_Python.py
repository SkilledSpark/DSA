# Bubble Sort

main_list = [12,11,13,5,6,12983,121983,1,1,0,3485,9,3,2,8,94,4945]

def swap(l1, i1, i2):
    l1[i1] += l1[i2]
    l1[i2] = l1[i1] - l1[i2]
    l1[i1] -= l1[i2]

def selection_sort(l1):
    for i in range(len(l1)):
        for j in range(i, len(l1)):
            if l1[i] > l1[j]:
                swap(l1, i, j)
    return l1

def swap2(l1, it):
    l1[it] += l1[it + 1]
    l1[it + 1] = l1[it] - l1[it + 1]
    l1[it] -= l1[it + 1]

def bubble_sort(l1):
    for i in range(len(l1)-1):
        if l1[i] <= l1[i+1]:
            continue
        else:
            swap2(l1, i)
            for j in range(i, 0, -1):
                if l1[j] >= l1[j-1]:
                    break
                else:
                    swap2(l1, j-1)
    return l1

def insertion_sort(l1):
    for i in range(1,len(l1)):
        key = l1[i]
        while i>=1 and l1[i-1] > key:
            l1[i] = l1[i-1]
            i-=1
        l1[i] = key
    return l1

print(selection_sort(main_list))
print(bubble_sort(main_list))
print(insertion_sort(main_list))
