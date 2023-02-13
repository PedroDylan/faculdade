num_pessoas = 3
soma_salarios = 0
soma_filhos = 0
lista_filhos =[]
lista_salarios = []
lista_baixa_renda = []

#pegando variáveis do user e colocando-as na lista
for i in range (num_pessoas):
    salario = float(input("Insira o salário: "))
    filhos = int(input("Isnira o número de filhos: "))

    lista_filhos.append(filhos)
    lista_salarios.append(salario)

#loops de repetição para calcular as somas das listas
#e ver quantas pessoas são baixa renda
for x in lista_salarios:
    soma_salarios += x
    if x <= 1000:
        lista_baixa_renda.append(x)

for y in lista_filhos:
    soma_filhos += y

#definindo as médias
media_salarios = soma_salarios/(len(lista_salarios))
media_filhos = soma_filhos/(len(lista_filhos))

#achando porcentagem
porcentagem = (len(lista_baixa_renda)/len(lista_salarios))*100


print("A média salarial é {}".format(media_salarios))
print("A média de filhos é {}".format(media_filhos))
print("A porcentagem de pessoas baixa renda é {}%".format(porcentagem))



