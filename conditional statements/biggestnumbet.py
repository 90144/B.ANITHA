a, b = 4, 7
if a > b:
    print("Biggest is:", a)
else:
    print("Biggest is:", b)



    #among three numbers
    a, b, c = 7, 4, 9
if a > b and a > c:
    print("Biggest is:", a)
elif b > c:
    print("Biggest is:", b)
else:
    print("Biggest is:", c)

    #second biggest number among thrfee numbers
a, b, c = 10, 25, 18

if (a > b and a < c) or (a > c and a < b):
    print("Second biggest:", a)
elif (b > a and b < c) or (b > c and b < a):
    print("Second biggest:", b)
else:
    print("Second biggest:", c)