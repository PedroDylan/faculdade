def checa_primo(x):
    primo = True
    i = 2
    while i < x:
        if x%i == 0:
            primo = False
            break
        i += 1

    return primo 

def lista_primos(lista):
    dummy_list = []
    for x in lista: 
        if checa_primo(x):
            dummy_list.append(x)

    return dummy_list

def conta_lista(lista):
    number = 0
    for x in lista:
        number += 1

    return number


lista = []
for i in range(10):
    n = int(input("Insira um inteiro: "))
    lista.append(n)

primos = lista_primos(lista)
x = conta_lista(primos)
print(lista)
print(primos)
print(x)


