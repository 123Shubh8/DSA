def accept():
    s = set()
    n = int(input("\nHow many numbers do you want in set: "))
    for i in range(n):
        s.add(int(input(f"\nEnter number {i+1}: ")))
    return s

def remove_no(n, s):
    i = search(n, s)
    if n in s:
        s.remove(n)
    else:
        print(f"\n{n} does not found in set")
    return s

def display(s):
    itr = iter(s)
    print("\nSet elements are:\n")
    for i in s:
        print(next(itr))

def search(n, s):
    for i in s:
        if n in s:
            return i
        else:
            return -1

def find_size(s):
    cnt = 0
    for i in s:
        cnt += 1
    return cnt

def union_set(s1, s2):
    result = set()
    for i in s1:
        result.add(i)
    for j in s2:
        if j not in s1:
            result.add(j)
    return result

def intersection_set(s1, s2):
    result = set()
    for i in s1:
        if i in s2:
            result.add(i)
    return result

def difference_set(s1, s2):
    result = set()
    for i in s1:
        if i not in s2:
            result.add(i)
    return result

def subset(s1):
    if not s1:
        return [[]]
    x = subset(s1[:-1])
    return x + [[s1[-1]] + y for y in x]

def set_operation():
    s1 = accept()
    s2 = accept()
    uni = union_set(s1, s2)
    inter = intersection_set(s1, s2)
    diff_s1_s2 = difference_set(s1, s2)
    diff_s2_s1 = difference_set(s2, s1)
    print("\nSet 1:", s1)
    print("\nSet 2:", s2)
    print("\nUnion:", uni)
    print("\nIntersection:", inter)
    print("\nDifference (S1 - S2):", diff_s1_s2)
    print("\nDifference (S2 - S1):", diff_s2_s1)

# Main
s1 = accept()
print("\nSet is:", s1)
display(s1)

num = int(input("\nEnter the number to remove: "))
s1 = remove_no(num, s1)
print("\nSet after removal:", s1)

num = int(input("\nEnter the number to search: "))
i = search(num, s1)
if i != -1:
    print(f"\n {num} is present in set ")
else:
    print(f"\n {num} does not found in set ")
print("\nSet is:", s1)

size = find_size(s1)
print(f"\nSize of the set is: {size}")

set_operation()
