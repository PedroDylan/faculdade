from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import mean_squared_error

random_state = 42

X,y = make_classification(
    n_samples = 1000,
    n_features = 2 ,
    n_informative = 2,
    n_redundant=0,
    n_classes = 2 ,
    random_state = random_state
)

x_train, x_test, y_train, y_test = train_test_split(X,y,test_size=0.3,random_state=random_state)

model = LogisticRegression(random_state=random_state).fit(x_train,y_train)

y_esperado = model.predict(x_test)
erro = mean_squared_error(y_esperado,y_test)
print("Erro (MSE): ",erro)
print(model.score(x_train,y_train))
print(model.score(x_test,y_test))


