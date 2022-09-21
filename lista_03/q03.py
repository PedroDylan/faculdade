def calcula_fibonacci(x):
    
    if x ==0:
        return 0
    elif x == 1:
        return 1
    elif x==2:
        return 1 

    f = calcula_fibonacci(x-1) + calcula_fibonacci(x-2)
    return f

for i in range(13):
    print(calcula_fibonacci(i))
