import numpy as np
class Processo:
    def __init__(self, id, chegada, burst_time):
        self.id = id
        self.chegada = chegada
        self.burst_time = burst_time
        self.tempo_restante = burst_time
        self.tempo_espera = 0
        self.tempo_retorno = 0
        self.tempo_inicio = -1
        self.tempo_finalizacao = 0

def generate_process(N, max_chegada=10,max_burst=10):
    processos=[]
    for id in range(1,N+1):
        tempo_chegada = np.random.randint(0,max_chegada)
        tempo_burst = np.random.randint(1,max_burst)
        processos.append(Processo(id,tempo_chegada,tempo_burst))

    return sorted(processos, key= lambda x : x.chegada)