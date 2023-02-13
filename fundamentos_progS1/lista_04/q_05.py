class Funcionario():
    def __init__(self,nome, idade ,sexo, trabalho):
        self.nome = nome
        self.idade = idade
        self.sexo = sexo 
        self.trabalho = trabalho       
        self.apto = False

    def aposentadoria(self):
        if self.sexo == "homem" and self.idade >= 65 and self.trabalho >= 35:
            self.apto = True
        elif self.sexo == "mulher" and self.idade >= 60 and self.trabalho >= 30:
            self.apto = True
        else:
            self.apto = False

        if self.apto:
            return("{} apto para aposentadoria".format(self.nome))
        else: 
            return("{} não apto para aposentadoria".format(self.nome))

num_func = 6
lista_func = []
for i in range(num_func):
    nome = str(input("Insira o nome: "))
    idade = int(input("Insira a idade: "))
    sexo = str(input("Insira o sexo: "))
    trabalho = int(input("insira o número de anos trabalhados: "))

    jon_doe = Funcionario(nome,idade,sexo,trabalho)
    lista_func.append(jon_doe) 

for x in lista_func:
    print(x.nome)
    print(x.idade)
    print(x.sexo)
    print(x.trabalho)
    print(x.aposentadoria())
    