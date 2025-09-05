#Esse arquivo visa resolver o mesmo problema do arquivo 2
#usando as ferramentas disponíveis no sklearn sem implementar
#os cálculos básicos do zero
from ucimlrepo import fetch_ucirepo 
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from sklearn import linear_model

student_performance = fetch_ucirepo(id=320) 

X = student_performance.data.features[["traveltime","studytime","freetime"]]
y = student_performance.data.targets [["G3"]]

x_train , x_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=42)

#Criação do modelo linear
reg = linear_model.LinearRegression()
#Aplicação do conjunto de dados de entrada e saída no modelo linear
reg.fit(x_train,y_train)

#O modelo ja possui os atributos referentes aos coeficientes 
print("Intercepto (β0):", reg.intercept_)
print("Coeficientes (β1, β2, β3):", reg.coef_)

#Criação do vetor de valores esperados para o conjunto de testes
y_esperado = reg.predict(x_test)
#cálculo do erro 
erro = mean_squared_error(y_test,y_esperado)
print("Erro (MSE): ",erro)
