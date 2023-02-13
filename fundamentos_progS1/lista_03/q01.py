numeros = []

for i in range(10):
    x = int(input("insira o numero de posicao {}: ".format(i)))
    numeros.append(x)

numeros.sort()

maior = numeros[-1]
menor = numeros[0]

print(maior)
print(menor)