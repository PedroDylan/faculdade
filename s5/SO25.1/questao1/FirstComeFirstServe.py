from Processo import Processo

def fcfs(processos):
    n = len(processos)
    fila_prontos = sorted(processos, key=lambda x: x.chegada)
    tempo_atual = 0
    sequencia_execucao = []
    tempos_espera = [0] * n
    tempos_retorno = [0] * n

    for i in range(n):
        processo = fila_prontos[i]
        if tempo_atual < processo.chegada:
            tempos_espera[i] = processo.chegada - tempo_atual
            tempo_atual = processo.chegada
        tempo_inicio = tempo_atual
        sequencia_execucao.append((processo.id, tempo_inicio, tempo_inicio + processo.burst_time))
        tempo_fim = processo.burst_time + tempo_inicio
        tempos_retorno[i] = tempo_fim - processo.chegada
        tempo_atual = tempo_fim
    
    return sequencia_execucao, tempos_espera, tempos_retorno