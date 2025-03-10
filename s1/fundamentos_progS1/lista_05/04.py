def fibonacci(n):
    if n == 0:
        return 0
    elif n ==1:
        return 1
    elif n ==2:
        return 1

    return fibonacci(n-1) + fibonacci(n-2)

list_fib = [fibonacci(i) for i in range(21)]

print(list_fib)