number = int(input("Insira o total de maçãs: "))
total = 0
if number < 12:
    total = number*1.3
elif number >= 12:
    total = number

print(format(total, '.2f'))