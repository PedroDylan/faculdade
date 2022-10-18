class Complex:
    def __init__(self,real,imaginary):
        self.real = real
        self.imaginary = imaginary

    def __str__(self) -> str:
        return ("{} + {}i".format(self.real,self.imaginary)) 
        
def soma(a,b):
    re = a.real + b.real
    img = a.imaginary + b.imaginary 

    result = Complex(re,img)
    return result


def subtração(a,b):
    re = a.real - b.real
    img = a.imaginary - b.imaginary 

    result = Complex(re,img)
    return result


def multiplicação(a,b):
    
    re = ((a.real*b.real) - (a.imaginary*b.imaginary))
    img = (a.real*b.imaginary) + (a.imaginary*b.real) 
    
    result = Complex(re,img)
    return result

def divisão(a,b):
    
    re = (a.real*b.real + a.imaginary*b.imaginary)/((b.real**2)+(b.imaginary**2))
    img = (a.imaginary*b.real - a.real*b.imaginary)/((b.real**2)+(b.imaginary**2))
    
    result = Complex(re,img)
    return result
    
a = int(input("Insira a parte real: "))
b = int(input("Insira a parte imaginária: "))
c = int(input("Insira a parte real: "))
d = int(input("Insira a parte imaginária: "))

z1 = Complex(a,b)
z2 = Complex(c,d)

adic = soma(z1,z2)
sub = subtração(z1,z2)
mult = multiplicação(z1,z2) 
div = divisão(z1,z2)

print(adic)
print(sub)
print(mult)
print(div)