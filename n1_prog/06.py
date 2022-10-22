def calcula_fgts(n):
    return n*(0.085)

numero_pessoas = 5
lista_fgts = []

for n in range(numero_pessoas):
    salario = int(input("Insira seu salário: "))
    lista_fgts.append(calcula_fgts(salario))

maior = max(lista_fgts)
menor = min(lista_fgts)
print(lista_fgts)
print(maior)
print(menor)
print(maior-menor)