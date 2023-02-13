import random

numbers = []
i=0
while i <= 10:
    x = random.randrange(1,100)
    numbers.append(x)
    i += 1

print(numbers)
numbers.sort()
print(numbers)
numbers.sort(reverse=True)
print(numbers)