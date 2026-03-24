matrix=[[1,2,3],[4,5,6],[7,8,9]]
for row in matrix:
    row_sum=0
    for num in row:
        row_sum+=num
    print(f"Sum of {row} is {row_sum}")