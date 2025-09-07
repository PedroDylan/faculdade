from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
import scipy.special as scp
import numpy as np

X,y = make_classification(
    n_samples = 1000,
    n_features = 2 ,
    n_informative = 2,
    n_redundant=0,
    n_classes = 2 ,
    random_state = 42
)

x_train, x_test, y_train, y_test = train_test_split(X,y,test_size=0.3,random_state=42)

coluna_uns_train = np.ones((x_train.shape[0],1))
x_train_aug = np.hstack((coluna_uns_train,x_train))
coluna_uns_test = np.ones((x_test.shape[0],1))
x_test_aug = np.hstack((coluna_uns_test,x_test))

w = np.zeros((3,1))
weight = (0.0001)
y_train=y_train.reshape(700,1)
y_test = y_test.reshape(300,1)

for t in range(1,10):
  aux = x_train_aug @ w
  aux = (-y_train)*aux
  aux = scp.expit(aux)
  aux = y_train * aux
  aux = aux * x_train_aug
  grad = np.sum(aux)
  w = w - weight*grad

y_esperado = x_test_aug @ w
erro = np.mean((y_esperado-y_test)**2)
print(erro)

