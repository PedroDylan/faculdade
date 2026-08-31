import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from ucimlrepo import fetch_ucirepo 
from sklearn.model_selection import train_test_split
from polynomial_regression import PolynomialRegression

if __name__ == "__main__":
    seed=42
    alpha = 0.01
    array_alpha =[0.01,0.03,0.1,0.3,1]
    n_iterations = 1000
    auto_mpg = fetch_ucirepo(id=9) 

    X = auto_mpg.data.features[['horsepower']]
    y = auto_mpg.data.targets 
    df = pd.concat([X, y], axis=1).dropna()
    X = df[['horsepower']]
    y = df[auto_mpg.data.targets.columns]

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=seed)
    X_train = X_train.values
    X_test = X_test.values
    y_train = y_train.values.ravel()
    y_test = y_test.values.ravel()

    array_models=[]
    array_preds=[]
    for grau in range(1,11):
        model = PolynomialRegression(degree=grau, learning_rate=alpha, n_iterations=n_iterations)
        model.fit(X_train, y_train)
        array_models.append(model)    

    # ordem = np.argsort(X_test.flatten())
    # X_test_ordenado = X_test[ordem]
    # #Y_pred_ordenado = Y_pred[ordem]
    
    plt.figure(figsize=(10, 6))
    for model in array_models:
        plt.plot(range(model.n_iterations), model.cost_history, label=f'Grau {model.degree}')
    plt.yscale('log')
    plt.title('Convergência do MSE por iteração')
    plt.xlabel('Iterações')
    plt.ylabel('MSE (treino)')
    plt.legend()
    plt.show()

