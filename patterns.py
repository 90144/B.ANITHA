#solid square pattern
n=5
for i in range(n):
    for j in range (n):
        print("*",end=" ")
    print()

#solid rectangle pattren
m=8
n=5
for i in range(n):
    for j in range(m):
        print("*",end=" ")
    print()

#left triangle pattren
n=5
for i in range(1,n+1):
    for j in range(i):
        print("*",end=" ")
    print()

n = 5

for i in range(1, n + 1):
    print("  " * (n - i), end="")
    for j in range(i):
        print("*", end=" ")
    print()

    
# Inverted Triangle
n = 5

for i in range(n, 0, -1):
    for j in range(i):
        print("*", end=" ")
    print()


#Pyramid Pattern
n = 4

for i in range(1, n + 1):
    print(" " * (n - i), end="")
    for j in range(2 * i - 1):
        print("*", end=" ")
    print()


# Diamond Pattern
n = 3

for i in range(1, n + 1):
    print(" " * (n - i), end="")
    for j in range(2 * i - 1):
        print("*", end=" ")
    print()

for i in range(n - 1, 0, -1):
    print(" " * (n - i), end="")
    for j in range(2 * i - 1):
        print("*", end=" ")
    print()


# Hollow Square
n = 4

for i in range(n):
    for j in range(n):
        if i == 0 or i == n - 1 or j == 0 or j == n - 1:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()


#Hollow Rectangle
rows = 4
cols = 5

for i in range(rows):
    for j in range(cols):
        if i == 0 or i == rows - 1 or j == 0 or j == cols - 1:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()


# Hollow Triangle
n = 5

for i in range(1, n + 1):
    for j in range(1, i + 1):
        if j == 1 or j == i or i == n:
            print("*", end=" ")
        else:
            print(" ", end=" ")
    print()



# Increasing Number Triangle
n = 5

for i in range(1, n + 1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print()


# Repeating Row Number
n = 5

for i in range(1, n + 1):
    for j in range(i):
        print(i, end=" ")
    print()


# Continuous Number Triangle
n = 4
num = 1

for i in range(1, n + 1):
    for j in range(i):
        print(num, end=" ")
        num += 1
    print()


# Reverse Number Triangle
n = 5

for i in range(1, n + 1):
    for j in range(i, 0, -1):
        print(j, end=" ")
    print()


# Pascal Triangle
n = 5

for i in range(n):
    num = 1
    for j in range(i + 1):
        print(num, end=" ")
        num = num * (i - j) // (j + 1)
    print()
