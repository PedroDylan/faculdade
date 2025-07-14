from collections import deque
from Processo import Processo

def round_robin(processos, quantum, mudança_contexto=1):
    tempo_atual=0
    fila_prontos=deque()
    copia_processos = [p for p in processos]
    completos = []

    #Enquanto houverem processos na fila de prontos ou na lista de processos 
    while copia_processos or fila_prontos:
        while copia_processos and copia_processos[0].chegada <= tempo_atual:
            #Tirando o processo do topo da lista de processos e colocando na fila de prontos
            fila_prontos.append(copia_processos.pop(0))
        
        if fila_prontos: 
            p=fila_prontos.popleft()
            #analisa se o tempo inicial de p é o default ou se ja foi inicializado
            if p.tempo_inicio == -1:
                p.tempo_inicio = tempo_atual

            #Primeiro definimos o time slice e depois o removemos do tempo 
            #restante do processo, assim como o adicionamos no tempo atual
            time_slice = min(quantum,p.tempo_restante)
            p.tempo_restante -= time_slice
            tempo_atual += time_slice

            # Atualiza tempos de espera para outros processos na fila 
            # com o time slice definido 
            for p_esperando in fila_prontos:
                p_esperando.tempo_espera += time_slice

            #verifica se o processo terminou, se sim, marca o tempo 
            #atual como o momento de finalização, calcula o tempo de retorno 
            #e adiciona o processo na lista de completos. Senão, apenas adiciona
            #o processo na lista de prontos  
            if p.tempo_restante ==0:
                p.tempo_finalizacao = tempo_atual
                p.tempo_retorno = p.tempo_finalizacao - p.chegada
                completos.append(p)
            else:
                fila_prontos.append(p)
            
            #Tempo de mudança de contexto
            tempo_atual += mudança_contexto
        
        #Se não houver ninguém na fila de prontos simplesmente andamos com o tempo
        else:
            tempo_atual +=1
    return completos   

