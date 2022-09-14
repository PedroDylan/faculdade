number = int(input("Insira um inteiro: "))

def calcula_fatorial(x):
    prod = 1
    for i in range(1,x+1):
        prod *= i

    return prod

fat = calcula_fatorial(number)
print(fat)