import random

numbers = []
i=0
while i <= 10:
    x = random.randrange(1,100)
    numbers.append(x)
    i += 1
print(numbers)

repeated_numbers = set(())
for x in numbers:
    if numbers.count(x) > 1:
        repeated_numbers.add(x)
print(repeated_numbers)

    
    

