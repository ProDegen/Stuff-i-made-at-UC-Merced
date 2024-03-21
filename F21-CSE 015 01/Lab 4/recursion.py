import sys
sys.setrecursionlimit(100000)

def factorial(n):
    # Provide your code here
    if n < 2:
        return 1
    else:
        return n * factorial(n - 1)


print("factorial(5):")
print(factorial(5))

# Expected 120

def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    else:
        return fib(n-1)+fib(n-2)


# Provide your code here

print("fib(7):")
print(fib(7))


# Expected 13
def equal(a, b):
    if a[0] == b[0]:
        return "True"
    if a[0] != b[0]:
        return "False"
    else:
        a = a[0:]
        b = b[0:]
        return equal(a, b)


# Provide your code here
print("equal('ALICE', 'BOB):")
print(equal('ALICE', 'BOB'))
# Expected False
print("equal('ALICE', 'ALICE'):")
print(equal('ALICE', 'ALICE'))
# Expected True

def addup(list):
    if len(list)==0:
        return 0
    else:
        return list[0]+ addup(list[1:])


# Provide your code here

print("addup([1,2,3,4,5]):")
print(addup([1, 2, 3, 4, 5]))
# Expected 15
print("addup(range(101)):")
print(addup(range(101)))
# Expected 5050

def reverse(A):
    if A == "":
        return A
    else:
        return reverse(A[1:]) + A[0]


# Provide your code here

print("reverse('hello'):")
print(reverse("Hello"))
