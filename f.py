#Arbitrary Arguments (*args, **kwargs)
#Average of marks
def average_marks(*marks):
    if len(marks) == 0:
        return 0
    avg = sum(marks) / len(marks)
    print("Average:", avg)

average_marks(85, 90, 78, 92)
#Subjects + Student Details
def student_info(*subjects, **details):
    print("Subjects:")
    for sub in subjects:
        print(sub)

    print("\nStudent Details:")
    for key, value in details.items():
        print(f"{key}: {value}")

student_info("Math", "Science", "English", name="Anitha", age=21, grade="A", section="C")
#Products + Metadata
def product_info(*products, **metadata):
    print("Products:")
    for p in products:
        print(p)

    print("\nMetadata:")
    for key, value in metadata.items():
        print(f"{key}: {value}")

product_info("Laptop", "Phone", category="Electronics", brand="Dell", availability=True)

#Pure Functions
#Celsius → Fahrenheit
def celsius_to_fahrenheit(temps):
    return [(t * 9/5) + 32 for t in temps]

print(celsius_to_fahrenheit([0, 25, 30]))
#Cube of list
def cube_list(numbers):
    return [n**3 for n in numbers]

print(cube_list([1, 2, 3, 4]))
#Even or Odd
def check_even_odd(n):
    return "Even" if n % 2 == 0 else "Odd"

print(check_even_odd(7))

# Returning Multiple Values
# Sum and Average
def sum_and_avg(numbers):
    total = sum(numbers)
    avg = total / len(numbers)
    return total, avg

s, a = sum_and_avg([80, 90, 100])
print("Sum:", s, "Average:", a)
#Quotient and Remainder
def divide(a, b):
    return a // b, a % b

q, r = divide(10, 3)
print("Quotient:", q, "Remainder:", r)
#Square and Cube
def square_cube(n):
    return n**2, n**3

sq, cu = square_cube(4)
print("Square:", sq, "Cube:", cu)

#Recursive Functions
#Sum from 1 to n
def sum_n(n):
    if n == 1:
        return 1
    return n + sum_n(n - 1)

print(sum_n(5))
#Print n to 1
def print_desc(n):
    if n == 0:
        return
    print(n)
    print_desc(n - 1)

print_desc(5)
# Power (x^n)
def power(x, n):
    if n == 0:
        return 1
    return x * power(x, n - 1)

print(power(2, 4))



