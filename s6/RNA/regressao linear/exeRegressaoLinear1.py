import numpy as np
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

#geração de valores semialeatórios com seed registrada 
#para conferência de testes
seed = 7
np.random.seed(seed)

#implementação de definições da questão 
n_amostras = 100
X = np.random.uniform(-10,10,n_amostras)
epsilon = np.random.normal(0,2,n_amostras)
y = 3*X + 5 + epsilon
y = np.array(y)

#definição dos conjuntos de teste e de treino
x_train, x_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=seed)

#definição das variáveis para uso na fórmula
n = len(x_train)
x_ = sum(x_train)
y_ = sum(y_train)
xy_ = sum(x_train * y_train)
x_2 =sum([x*x for x in x_train])

#implementação da fórmula para encontrar os coeficientes
#da reta de regressão
w1 = (n*xy_ - x_*y_)/(n*x_2 - x_*x_)
w0 = (y_ - w1*x_)/n

#criação de valores para plotagem da reta
x_values = np.linspace(-10,10,n_amostras)
#definição da reta no plano
y_values = w0+w1*x_values

#resultado esperado pelo modelo no vetor de dados
y_resultado = w0 + w1*X
#calculo do erro 
err = np.mean((y_resultado - y)**2)

plt.scatter(x_train,y_train, c='g',label="Pontos de treino")
plt.scatter(x_test,y_test,c='r',label="Pontos de teste")
plt.plot(x_values,y_values)
plt.text(-10.5,25,f'erro = {err:.2}')
plt.legend()
plt.show()  
