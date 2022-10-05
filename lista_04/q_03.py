class Cliente:
    def __init__(self,nome,saldo):
        self.nome = nome
        self.saldo = saldo

    def sacar(self,valor):
        if valor <= self.saldo:
            self.saldo -= valor
        else:
            print("Saldo insuficiente")

    def credito(self,valor):
        self.saldo += valor

    def print_saldo(self):
        print(self.saldo) 
  
num_clientes = 5
lista_clientes  = []

for i in range(num_clientes):
    dummy_saldo = int(input("Insira o saldo: "))
    dummy_nome = str(input("Insira o nome: "))
    lista_clientes.append(Cliente(dummy_nome,dummy_saldo))

#operações baseadas no user
op = int(input("Qual operação deseja fazer? (1)Saque ou (2)Saldo: "))
qual_cliente = int(input("De qual conta deseja sacar?[1-5]: "))
valor = int(input("insira o valor: "))

if op == 1:
    lista_clientes[qual_cliente].sacar(valor)
elif op ==2:
    lista_clientes[qual_cliente].credito(valor)

print("O saldo final é: {}".format(lista_clientes[qual_cliente].saldo))




