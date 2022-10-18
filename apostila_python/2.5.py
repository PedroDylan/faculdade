from math import atan 

class Complex:
    def __init__(self,real,imaginary):
        self.real = real
        self.imaginary = imaginary

    def __str__(self):
        return ("{} + {}i".format(self.real,self.imaginary)) 

    def modulo(self):
        r2 = self.real**2 + self.imaginary**2
        r = r2**(1/2)

        return r

    def polar(self):
        r= self.modulo()    
        tan = self.real/self.imaginary
        teta = atan(tan)

        return ("{}<{}".format(r,teta))

    def trigonometria(self):
        r= self.modulo()
        cos = self.real/r
        sen = self.imaginary/r    

        return Complex(cos,sen)

        
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

print(z1.polar())
print(z2.polar())
# adic = soma(z1,z2)
# sub = subtração(z1,z2)
# mult = multiplicação(z1,z2) 
# div = divisão(z1,z2)

# print(adic)
# print(sub)
# print(mult)
# print(div)