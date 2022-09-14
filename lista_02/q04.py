n1 = int(input('insira um inteiro: '))
n2 = int(input('insira um inteiro: '))
n3 = int(input('insira um inteiro: '))

if n1 > n2 and n1 > n3:
    maior = n1
elif n2 > n1 and n2 > n3:
    maior = n2
elif n3>n2 and n3>n1:
    maior = n3

print(maior)