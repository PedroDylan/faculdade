num_func = 2
num_sem = 4
lista_horas = []
for i in range(num_func):
    #recebendo inputs
    num_horas = int(input("Insira o número de horas mensais: "))
    sal_hora = int(input("Insira o salario por hora: "))
    
    #calculando horas extras
    if num_horas >= 40:
        hora_ex = num_horas - 40
        total_mes = 40*sal_hora + hora_ex*sal_hora*1.5
    else: 
        total_mes= num_horas*sal_hora

    lista_horas.append(num_horas)
    print(total_mes)

print(max(lista_horas))

