op = str(input("Insira um operador"))

multiplicadores = [1,2,3,4,5,6,7,8,9,10]
numeros = [1,2,3]

for n in numeros:
    if op == "+":
        for m in multiplicadores:
            print(n+m)
    elif op == "*":
        for m in multiplicadores:
            print(n*m)
    elif op == "/":
        for m in multiplicadores:
            print(n/m)
    elif op == "-":
        for m in multiplicadores:
            print(n-m)