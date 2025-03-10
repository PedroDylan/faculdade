numero_pessoas = 10
idades = []
for i in range(numero_pessoas):
    x = int(input("Insira o ano de nascimento :"))  
    idade = 2022 - x
    idades.append(idade)

print(idades)
idades.sort()
print(idades[0])
print(idades[-1])