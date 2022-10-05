class Funcionario():
    def __init__(self,nome, idade ,sexo, trabalho):
        self.nome = nome
        self.idade = idade
        self.sexo = sexo 
        self.trabalho = trabalho       
        self.apto = False

    def aposentadoria(self):
        if self.sexo == "Homem" and self.idade >= 65 and self.trabalho >= 35:
            self.apto = True
        elif self.sexo == "Mulher" and self.idade >= 60 and self.trabalho >= 30:
            self.apto = True
        else:
            self.apto = False

        if self.apto:
            print("{} apto para aposentadoria".format(self.nome))
        else: 
            print("{} não apto para aposentadoria".format(self.nome))


        

joao = Funcionario("Joao", 85, "Homem", 40)
marcelo = Funcionario("Marcelo", 40, "Homem", 20)
carla = Funcionario("Carla", 70, "Mulher", 45)
joao.aposentadoria()
carla.aposentadoria()
marcelo.aposentadoria()