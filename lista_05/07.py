import random

def is_even(x):
    return True if x%2==0 else False

def even_list(list):
    dummy = []
    for x in list:
        if is_even(x):
            dummy.append(x)
    return dummy

numbers = []
i=0
while i <= 10:
    x = random.randrange(1,100)
    numbers.append(x)
    i += 1

even_numbers = even_list(numbers)
print(numbers)
print(even_numbers)
print(len(even_numbers))
