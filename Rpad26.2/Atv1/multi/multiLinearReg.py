import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score 
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

def normalizar(x:np.ndarray) -> np.ndarray:
    #Normalizar os dados para que tenham média 0 e desvio padrão 1
    media = x.mean(axis=0)
    desvio = x.std(axis=0)
    return (x - media) / desvio

def MSE(x : np.ndarray, y : np.ndarray, theta : np.ndarray) -> float:
    #Função de custo padrão definida como a média das diferenças entre os valores preditos e os reais ao quadrado
    m = len(y)
    predictions = x.dot(theta)
    error = predictions - y
    mse = (1/m) * np.sum(error ** 2)
    return mse  

def gradiente_descendente(x:np.ndarray, y:np.ndarray, theta:np.ndarray, alpha:float, num_iter:int) -> tuple:
    #Para cada iteração é calculada a predição e o erro dela com o valor real, depois o theta é 
    #atualizado pelo vetor de gradiente multiplicado pela taxa de aprendizagem e o erro é salvo no histórico
    m = len(y)
    historico = np.zeros(num_iter)
    for i in range(num_iter):
        predictions = x.dot(theta)
        error = predictions - y
        gradient = (1/m) * x.T.dot(error)
        theta -= alpha * gradient
        historico[i] = MSE(x, y, theta)
    return theta, historico

def regression(x:np.ndarray, y:np.ndarray, alpha:float, num_iter:int) -> tuple:
    #Essa função equivale ao model do Scikit pois basicamente implementa o gradiente descendente e calcula o MSE
    theta = np.zeros(x.shape[1])
    theta, historico = gradiente_descendente(x, y, theta, alpha, num_iter)
    mse = MSE(x, y, theta)
    r2 = r2_score(y, x.dot(theta))
    return theta, historico, mse , r2

def regressao_com_sklearn(x:np.ndarray, y:np.ndarray) -> tuple:
    model = LinearRegression()
    model.fit(x, y)
    theta = np.concatenate(([model.intercept_], model.coef_))
    predictions = model.predict(x)
    mse = np.mean((predictions - y) ** 2)
    r2 = r2_score(y, predictions)
    return theta, mse, r2



if __name__ == "__main__":
    alpha = [0.001,0.003,0.01,0.03,0.1]
    num_iter=1000
    seed=42

    df = pd.read_csv("Atv1/multi/housing-prices-dataset/versions/1/Housing.csv")
    print(df.head())
    df = df.replace({'yes': 1, 'no': 0})

    x=df[['area' , 'bedrooms', 'bathrooms', 'stories', 'mainroad', 'guestroom', 'basement', 'hotwaterheating', 'airconditioning', 'parking', 'prefarea']].values.astype(float)
    y=df['price'].values.astype(float)

    X_train, X_test, y_train, y_test=train_test_split(x, y, test_size=0.2, random_state=seed)
    X_train = normalizar(X_train)
    X_test = normalizar(X_test)
    X_train_bias =  np.hstack([np.ones((X_train.shape[0], 1)), X_train])


    vetor_thetas = []
    vetor_historicos = []
    vetor_mse = []
    vetor_r2 = []
    for a in alpha:
        theta_teste, historico_teste, mse_teste, r2_teste = regression(
            X_train_bias, y_train, a, num_iter
        )
        vetor_thetas.append(theta_teste)
        vetor_historicos.append(historico_teste)
        vetor_mse.append(mse_teste)
        vetor_r2.append(r2_teste)

    theta_sklearn, mse_sklearn,r2_sklearn = regressao_com_sklearn(X_train, y_train)
    
    print("Theta do 0:", vetor_thetas[-1])
    print("MSE do 0:", vetor_mse[-1]) 
    print("R2 do 0:", vetor_r2[-1])
    print("RMSE do 0:", np.sqrt(vetor_mse[-1]))
    print("Erro relativo médio do 0:", np.sqrt(vetor_mse[-1]) / y_train.mean())
    print("Theta do sklearn:", theta_sklearn)
    print("MSE do sklearn:", mse_sklearn) 
    print("R2 do sklearn:", r2_sklearn)
    print("RMSE do sklearn:", np.sqrt(mse_sklearn))
    print("Erro relativo médio do sklearn:", np.sqrt(mse_sklearn) / y_train.mean())


    for i, (theta, historico) in enumerate(zip(vetor_thetas, vetor_historicos)):
        plt.plot(range(1, num_iter + 1), historico, label=f"alpha={alpha[i]}")

    plt.xlabel("Iteração")
    plt.ylabel("MSE (custo)")
    plt.title("Convergência do Gradiente Descendente")
    plt.legend()
    plt.grid(True)
    plt.show()
    