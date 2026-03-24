words=["Apple","Banana","Cherry","Date","Elderberry"]
vowels="AEIOUaeiou"
for word in words: 
    count=0
    for char in word: 
        if char in vowels: 
            print(char, end=" ") 
            count += 1
    print(f"Number of vowels in {word}: {count}")