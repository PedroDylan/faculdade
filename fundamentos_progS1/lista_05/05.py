def is_even(x):
    return True if x%2==0 else False

def even_list(list):
    dummy = []
    for x in list:
        if is_even(x):
            dummy.append(x)
    return dummy

list_numbers = [i for i in range(10,21)]
list_even = even_list(list_numbers)
list_even.sort(reverse=True)

print(list_even)


