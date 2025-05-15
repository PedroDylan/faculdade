from Processo import Processo
from typing import List
import numpy as np


def calcular_metricas(processos):
    #Definindo arrays com os tempos
    array_tempo_espera =[]
    array_tempo_retorno=[]
    for p in processos:
        if (isinstance(p,Processo)):
            array_tempo_retorno.append(p.tempo_retorno)
            array_tempo_espera.append(p.tempo_espera)

    #Definindo throughput com base na existência ou não de elementos
    #em processos
    throughput = 0
    if(isinstance(p,Processo)):
        if processos :
            throughput = len(processos) / max(p.tempo_finalizacao for p in processos)

            

    media_espera = np.mean(array_tempo_espera)
    desvio_espera = np.std(array_tempo_espera)
    media_retorno = np.mean(array_tempo_retorno)
    desvio_retorno = np.std(array_tempo_retorno) 

    return {
        'media_espera' : media_espera,
        'desvio_espera' : desvio_espera,
        'media_retorno' : media_retorno,
        'desvio_retorno' : desvio_retorno,
        'throughput' : throughput
    }