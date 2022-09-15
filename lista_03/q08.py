numero_funcionarios = 3
salarios = []
for i in range(numero_funcionarios):
    x = int(input("insira o salário: "))
    salarios.append(x)

def calcula_media(lista):
    y = len(lista)
    sum = 0 
    for x in lista:
        sum += x
    return sum/y

def imposto_renda(y):
    if y <= 1500:
        return 0
    elif 1500 < y <= 2000:
        return y*0.1
    elif 2000 < y:  
        return y*0.15

print(salarios)

for i in range(len(salarios)):
    salario_liquido = salarios[i]-imposto_renda(salarios[i])
    x = imposto_renda(salarios[i])
    print("O imposto de renda do funcionário {} é: {}".format(i,x))
    y = salario_liquido
    print("O salario líquido do mesmo é: {}".format(y))

salarios.sort()
menor = salarios[0]
maior = salarios[-1]
print("O menor salário da lista é: {}".format(menor))
print("O maior salário da lista é: {}".format(maior))
print("A média salarial é: {}".format(calcula_media(salarios)))