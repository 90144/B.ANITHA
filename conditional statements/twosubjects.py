m, p, c = 40, 20, 36
count = 0

if m >= 35:
    count += 1
if p >= 35:
    count += 1
if c >= 35:
    count += 1

if count >= 2:
    print("Pass")
else:
    print("Fail")