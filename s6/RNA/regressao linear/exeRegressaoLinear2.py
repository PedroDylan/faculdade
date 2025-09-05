import numpy as np
from ucimlrepo import fetch_ucirepo 
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

#puxando dataset do archive.ics.uci.edu
student_performance = fetch_ucirepo(id=320) 

#Selecionando apenas 3 colunas compostas por inteiros para as variáveis 
#independentes e a nota final para a variavel dependente 
X = student_performance.data.features[["traveltime","studytime","freetime"]]
y = student_performance.data.targets [["G3"]]

#Separando conjuntos de teste e de treino
x_train , x_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=42)

#Essa linha adiciona uma coluna de 1s na primeira coluna dos conjuntos
#para que seja realizada a multiplicação pelo coeficiente independente.
#np.ones((x_train.shape[0], 1)) == coluna de uns do tamanho da primeira coluna de x_train_shape
#np.c_ é responsável por "concatenar" duas matrizes
x_train_aug = np.c_[np.ones((x_train.shape[0], 1)),x_train]
x_test_aug = np.c_[np.ones((x_test.shape[0], 1)),x_test]

#Vetor de coeficientes beta através da 
#fórmula da regressão linear multivariável β=(X⊤X)−1X⊤y
beta = np.linalg.inv(x_train_aug.T @ x_train_aug) @ x_train_aug.T @ y_train

#Resultados esperados para o conjunto de teste
y_esperado = x_test_aug @ beta

#Erro médio do modelo comparando o conjunto de resultados esperados
#com o conjunto de teste 
mse = mean_squared_error(y_esperado,y_test)

print(f"MSE: {mse:.2f}")
print(f"Coeficientes: {beta}")




