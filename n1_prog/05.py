def acha_menor(a,b):
    if a<b:
        return a
    else:
        return b

def consumo(n):
    return n/12

c1 = int(input("Insira o comprimento do percurso 1: "))
c2 = int(input("Insira o comprimento do percurso 2: "))

menor = acha_menor(c1,c2)
gas = consumo(menor)

print("O menor percurso é o de {} Kms e seu consumo é de {} litros".format(menor,gas))

