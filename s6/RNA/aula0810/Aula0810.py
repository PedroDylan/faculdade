#Usar dataloaders em pytorch -> fazer treinamento em batchs de tamanho variável Gerar curvas de aprendizagem
#Naive MLP

import torch
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

#Definindo a classe Multi layered perceptron para uso com o pytorch
class MLP(torch.nn.Module):
    def __init__(self, n_inputs, n_outputs, n_layers, n_hidden):
        super(MLP, self).__init__()
        self.n_layers = n_layers
        self.layers = torch.nn.ModuleList()
        #Loop criando as camadas de neurônios appendando as camadas 
        #via torch.neuralNetwork, que recebe os números de neurônios em 
        #cada camada
        for i in range(n_layers - 1):
            if i == 0:
                self.layers.append(torch.nn.Linear(n_inputs, n_hidden))
            else:
                self.layers.append(torch.nn.Linear(n_hidden, n_hidden))

        #Esse método, tanto aqui quanto no loop acima é responsável por 
        # criar as ligações entre as camadas de neurônios 
        self.layers.append(torch.nn.Linear(n_hidden, n_outputs))

    #Esse método é responsável for avançar os dados nas camadas de neurônios
    #pela redefinição do dado através da sua aplicação em cada camada até ele ser aplicado
    #na última camada e retornado
    def forward(self, x):
        for i in range(self.n_layers - 1):
            x = self.layers[i](x)
            x = torch.relu(x)
        x = self.layers[-1](x)
        return x


## Dados

# Criando dados para análise com uma função com variância
x = torch.arange(-4, 4, 0.01).unsqueeze(1)
y = 0.1*x**2 + torch.sin(2*x) + 0.1*torch.randn(x.shape[0], x.shape[1])
#Separando dados de teste e treino
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
#Criando datasets e dataloaders
train_dataset = torch.utils.data.TensorDataset(x_train, y_train)
test_dataset = torch.utils.data.TensorDataset(x_test, y_test)
train_loader = torch.utils.data.DataLoader(train_dataset, batch_size=10, shuffle=True)
test_loader = torch.utils.data.DataLoader(test_dataset, batch_size=10, shuffle=False)

plt.plot(x_train, y_train, '.',color='b')
plt.plot(x_test, y_test, '.',color='r')

#Função responsável por calcular o erro relativo em cada iteração
def evaluate_error(data_loader):
  model.eval()
  loss = 0
  count = 0
  for data in data_loader :
    y_hat = model.forward(data[0])
    loss += torch.sum((data[1] - y_hat)**2).item()
    count += data[0].shape[0]
  return loss/count

#Criação do modelo
model = MLP(1, 1, 5, 10)
model.eval()
#gerando predição com o vetor de treino
with torch.no_grad():
    pred = model.forward(x_train)

plt.plot(x_train, y_train, '.')
plt.plot(x_train, pred, '-')

#Fase de treino do modelo através do cálculo da função perda em cada época
model.train()
optimzer = torch.optim.Adam(model.parameters(), lr=0.01)
lista_erro_treino = []
lista_erro_teste = []
epochs = 300
for epoch in range(epochs):
    model.train()
    for data in train_loader:
      optimzer.zero_grad()
      y_hat = model.forward(data[0])
      loss = torch.sum((data[1] - y_hat)**2)
      loss.backward()
      optimzer.step()
    lista_erro_teste.append(evaluate_error(test_loader))
    lista_erro_treino.append(evaluate_error(train_loader))

plt.plot(lista_erro_teste, label='Treino',color='r')
plt.plot(lista_erro_treino, label='Teste',color='b')

#resultado final do modelo treinado
model.eval()
with torch.no_grad():
    pred = model(x) 
plt.plot(x, y, '.', label='Actual Data') 
plt.plot(x, pred,'.',color='g', label='Predictions') 
plt.legend()
plt.show()