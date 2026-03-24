numbers=[[1,2,3],[4,5,6],[7,8,9]]
even=0
odd=0
for i in range(len(numbers)):
    for j in range(len(numbers[0])):
        if numbers[i][j]%2==0:
            even+=1
        else:
            odd+=1
print(f"total even numbers: {even}")
print(f"total odd numbers: {odd}")