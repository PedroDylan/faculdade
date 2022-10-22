def checa_bissexto(n):
    bissexto = True

    if n%4 != 0:
        bissexto = False
    elif (n%4==0) and (n%100 != 0):
        bissexto = True
    elif (n%100==0) and (n%400 != 0):
        bissexto = False
    elif n%400==0:
        bissexto = True


    
    return bissexto

ano = int(input("Insira o ano: "))
print(checa_bissexto(ano))