n1 = float(input("Insira um número: "))
n2 = float(input("Insira outro número: "))
c = str(input("insira um operador: "))

if c == "+":
    result = n1 + n2
elif c == "*":
    result = n1 * n2
elif c == "-":
    result = n1 - n2
elif c == "/":
    result = n1 / n2
else:
    result = "Operação inválida"

print(result)
