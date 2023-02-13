import random

n = int(input("Digite o número que deseja: "))

numbers = []
i=0
while i <= 10:
    x = random.randrange(1,100)
    numbers.append(x)
    i = i+1


if numbers.count(n) == 0:
    print("Tente novamente mais tarde")
else:
    print("Achamos seu número!")


print(numbers)




