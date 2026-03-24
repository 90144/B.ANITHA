a=[1,2,3,4,5,6,7,8,9]
unique_pairs=[]
for i in range(len(a)): 
    for j in range(i+1, len(a)): 
        unique_pairs.append((a[i], a[j]))
print(unique_pairs)