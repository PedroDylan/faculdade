def fatora(n):
    divisores = []
    
    for i in range(2,n+1):
        if n%i == 0:
            divisores.append(i)

    return divisores

def compara(lista1,lista2):
    dummy_list = []
    for x in lista1:
        if x in lista2:
            dummy_list.append(x)

    return dummy_list

n1 = int(input("Insira o primeiro número: "))
n2 = int(input("Insira o segundo número: "))

fat1 = fatora(n1)
fat2 = fatora(n2)

print(fat1)
print(fat2)
print(compara(fat1,fat2))

mdc = max(compara(fat1,fat2))
print(mdc)

