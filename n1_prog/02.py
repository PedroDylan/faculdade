def acha_par(a,b) -> list:
    dummy_list = []
    for n in range(a,b+1):
        if (n%2 ==0):
            dummy_list.append(n)
    
    return dummy_list

def acha_impar(a,b) -> list:
    dummy_list = []
    for n in range(a,b+1):
        if (n%2 == 1):
            dummy_list.append(n)
    
    return dummy_list

def checa_primo(p) -> bool:
    primo = True
    for n in range(2,p):
        if (p%n == 0):
            primo = False

    return primo

def acha_primo(a,b) -> list:
    
    lista = [i for i in range(a,b+1)]
    lista_primos=[]

    for x in lista:
        if checa_primo(x):
            lista_primos.append(x)

    return lista_primos

lista_pares = acha_par(50,100)
lista_impares = acha_impar(50,100)
lista_primos = acha_primo(50,100)

number_primo = len(lista_primos)
number_par = len(lista_pares)
number_impar = len(lista_impares)

print("Existem {} pares no intervalo e eles são {}".format(number_par,lista_pares))
print("Existem {} ímpares no intervalo e eles são {}".format(number_impar,lista_impares))
print("Existem {} primos no intervalo e eles são {}".format(number_primo,lista_primos))