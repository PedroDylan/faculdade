import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report, confusion_matrix

random_state = 42

x = np.arange(10).reshape(-1,1)
y = np.array([0, 0, 0, 0, 1, 1, 1, 1, 1, 1])

model = LogisticRegression(random_state=random_state).fit(x,y)
predicao = model.predict(x)

print(y)
print(predicao)
print(model.score(x,y))
print(classification_report(y,predicao))