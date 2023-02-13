def square(x):
    return x*x

def add(x,y):
    return x+y

list_even = [2*x for x in range(1,11)]
list_squares = list(map(square,list_even))
list_numbers = [x for x in range(10,20)]

list_sum = list(map(add,list_squares,list_numbers))

print(list_even)
print(list_squares)
print(list_numbers)
print(list_sum)