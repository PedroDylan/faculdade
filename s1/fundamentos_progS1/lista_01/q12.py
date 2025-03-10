a = int(input('insira o coeficiente líder diferente de 0'))
b = int(input('insira o coeficiente linear'))
c = int(input('insira o coeficiente independente'))

delta = b**2 - 4*a*c
r1 =0
r2 =0

if(delta < 0):
    print('a equação não tem soluções reais')
else:
    r1 = (-b - delta**(1/2))/(2*a)
    r2 = (-b + delta**(1/2))/(2*a)
    print('as raízes são {} e {}'.format(r1,r2))


