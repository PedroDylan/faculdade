def mult_dias(n):
    return 365*n

nome = str(input("Qual o seu nome? "))
idade = int(input("Qual a sua idade? "))
dias = mult_dias(idade)

print("{}, você viveu {} dias.".format(nome,dias))