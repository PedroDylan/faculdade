numero_pessoas = 2
imcs = []
for i in range(numero_pessoas):
    x = float(input("Insira a altura: "))
    y = float(input("Insira o peso: "))
    imc = y / (x**2)
    imcs.append(imc)

def calcula_imc(lista):
    dummy_list = []
    for x in lista:
        if x < 18.5:
            dummy_list.append("abaixo do peso")
        elif 18.5 <= x <= 24.9:
            dummy_list.append("peso normal")
        elif 25 <= x <= 29.9:
            dummy_list.append("sobrepeso")
        elif 30 <= x <= 34.9:
            dummy_list.append("obesidade grau 1")
        elif 35 <= x <= 39.9:
            dummy_list.append("obdesidade grau 2")
        elif 40 <= x:
            dummy_list.append("obesidade grau 3 ou mórbida")

    return dummy_list

print(imcs)
print(calcula_imc(imcs))