quantidade = 4
lista = []

for i in range(quantidade):
    n = int(input("Insira um número: "))
    lista.append(n)

lista.sort()
print(lista)
lista.sort(reverse = True)
print(lista)
