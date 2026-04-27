# 1. Arbitrary Arguments (*args, **kwargs)

def checkout(*prices, **info):
    total = sum(prices)
    print("Total:", total)

    for key, value in info.items():
        print(f"{key}: {value}")

checkout(100, 200, 50, name="Alex", payment="Card")

def average_marks(*marks):
    if len(marks) == 0:
        print("No marks provided")
    else:
        avg = sum(marks) / len(marks)
        print("Average:", avg)

average_marks(85, 90, 78, 92)

def student_details(*subjects, **details):
    print("Subjects:")
    for sub in subjects:
        print(sub)

    print("\nStudent Details:")
    for key, value in details.items():
        print(f"{key}: {value}")

student_details("Math", "Science", "English",
                name="Anitha", age=21, grade="A", section="C")


def product_details(*products, **metadata):
    print("Products:")
    for p in products:
        print(p)

    print("\nMetadata:")
    for key, value in metadata.items():
        print(f"{key}: {value}")

product_details("Laptop", "Phone",
                category="Electronics", brand="Dell",
                price_range="50k-1L", availability=True)

# Function: Double list
def double_list(numbers):
    return [n * 2 for n in numbers]

print("Doubled List:", double_list([1, 2, 3]))

def celsius_to_fahrenheit(temps):
    return [(t * 9/5) + 32 for t in temps]

print("Fahrenheit:", celsius_to_fahrenheit([0, 25, 30]))

def cube_list(numbers):
    return [n ** 3 for n in numbers]

print("Cube List:", cube_list([1, 2, 3]))

# 3. Returning Multiple Values

def sum_and_avg(numbers):
    total = sum(numbers)
    avg = total / len(numbers)
    return total, avg

s, a = sum_and_avg([80, 90, 100])
print("Sum:", s, "Average:", a)


def divide(a, b):
    return a // b, a % b

q, r = divide(10, 3)
print("Quotient:", q, "Remainder:", r)

def square_cube(n):
    return n**2, n**3

sq, cu = square_cube(4)
print("Square:", sq, "Cube:", cu)


# 4. Recursive Functions

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

print("Factorial:", factorial(5))


def sum_n(n):
    if n == 1:
        return 1
    return n + sum_n(n - 1)

print("Sum 1 to n:", sum_n(5))


def print_desc(n):
    if n == 0:
        return
    print(n)
    print_desc(n - 1)

print("Print numbers from n to 1:")
print_desc(5)

def power(x, n):
    if n == 0:
        return 1
    return x * power(x - 0, n - 1)  # small safe form

print("Power:", power(2, 4))