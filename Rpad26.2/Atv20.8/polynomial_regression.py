import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from ucimlrepo import fetch_ucirepo 
from sklearn.model_selection import train_test_split

class PolynomialRegression():
    def __init__(self, degree: int, learning_rate: float, n_iterations: int):
        self.degree = degree
        self.learning_rate = learning_rate
        self.n_iterations = n_iterations

    def transform(self, X: np.ndarray) -> np.ndarray:
        m = X.shape[0]
        ones = np.ones((m, 1))
        potencias = [np.power(X, j) for j in range(1, self.degree + 1)]  # cada uma (m, n_features)
        X_poly = np.hstack(potencias)  # (m, n_features * degree)
        return np.hstack([ones, X_poly])  # (m, 1 + n_features * degree)

    def normalize_fit(self, X: np.ndarray) -> np.ndarray:
        # calcula média/desvio a partir do treino e guarda como atributos
        self.media = np.mean(X[:, 1:], axis=0)
        self.desvio_padrao = np.std(X[:, 1:], axis=0)
        X[:, 1:] = (X[:, 1:] - self.media) / self.desvio_padrao
        return X

    def normalize_transform(self, X: np.ndarray) -> np.ndarray:
        # reaplica média/desvio já calculados no treino
        X[:, 1:] = (X[:, 1:] - self.media) / self.desvio_padrao
        return X

    def fit(self, X: np.ndarray, y: np.ndarray) -> 'PolynomialRegression':
        self.X = X
        self.y = y
        self.m, self.n = self.X.shape

        X_transformed = self.transform(self.X)
        X_normalized = self.normalize_fit(X_transformed)

        self.weights = np.zeros(X_normalized.shape[1])  # <-- corrigido, antes era self.degree + 1

        self.cost_history = []

        for i in range(self.n_iterations):
            h = np.dot(X_normalized, self.weights)
            error = h - self.y

            mse_iter = np.mean(error ** 2)
            self.cost_history.append(mse_iter)

            self.weights -= self.learning_rate * (1 / self.m) * np.dot(X_normalized.T, error)

        return self


    def predict(self, X: np.ndarray) -> np.ndarray:
        X_transformed = self.transform(X)
        X_normalized = self.normalize_transform(X_transformed)  # <-- transform aqui, sem recalcular
        return np.dot(X_normalized, self.weights)
    
