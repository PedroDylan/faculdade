import numpy as np
import matplotlib.pyplot as plt

faltas = [(3648, 3648),
(2447, 2411),
(1621, 1517),
(1093, 1066),
(948, 900),
(885, 847),
(840, 805),
(809, 763),
(767, 729),
(725, 685),
(680, 640),
(642, 601),
(609, 555),
(565, 545),
(548, 544),
(545, 544),
(544, 544),
(544, 544),
(544, 544),
(544, 544),
(544, 544),
(544, 544),
(544, 538),
(517, 178),
(284, 113),
(26, 26),]

faltas_fifo = [x[0] for x in faltas]
faltas_aging = [x[1] for x in faltas]
numero_molduras = [i for i in range (26)]

fig, ax = plt.subplots()             
ax.plot(numero_molduras,faltas_aging,label='Envelhecimento')
ax.set_xlabel('Número de molduras')
ax.set_ylabel('Faltas de páginas')
ax.plot(numero_molduras,faltas_fifo,label='FIFO')
ax.legend()  
plt.grid(True)
plt.show()                           