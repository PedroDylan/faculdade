
from collections import deque

def fifo (ref, num_mold):
  memoria = deque() 
  faltas = 0
  for pagina in ref:
    if pagina not in memoria:
      faltas += 1
      if len(memoria) >= num_mold:
        memoria.popleft() 
      memoria.append(pagina)
    logs("FIFO", memoria, faltas)
  return faltas

def envelhecimento (ref, num_mold,bits=8):
  memoria = []
  frequencia = {}
  faltas = 0

  for pagina in ref:
    for p in memoria: 
      frequencia[p] >>= 1
    if pagina in memoria: 
      frequencia[pagina] |= 1 << (bits - 1)
    else:
      faltas += 1
      if len(memoria) >= num_mold:
        pag_sub = min(memoria, key=frequencia.get)
        memoria.remove(pag_sub)
        del frequencia[pag_sub]
      memoria.append(pagina)
      frequencia[pagina] = 256

    logs("ENVELHECIMENTO", memoria, faltas, frequencia)  
  return faltas

import json
from collections import defaultdict

global_logs = defaultdict(list)

def logs (algoritmo, memoria, faltas, frequencia=None, save_to_file=True):
  log_entry = {
      "memoria": list(memoria),
      "frequencia": frequencia if frequencia else None,
      "faltas": faltas
  }

  global_logs[algoritmo].append(log_entry)


from pathlib import Path

def save_logs_to_file(processos, logs, filename='/logs/memoria_logs.json'):
    try:
        Path(filename).parent.mkdir(parents=True, exist_ok=True)

        data_to_save = {
            "sequencia_processos": processos,
            "logs_algoritmos": logs
        }
        
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(data_to_save, f, indent=4, ensure_ascii=False)
            
        print(f"Logs salvos com sucesso em: {filename}")
    except (IOError, OSError) as e:
        print(f"Erro ao salvar logs: {str(e)}")
        raise
  

def simular (ref, num_mold):
  faltas_fifo = fifo(ref, num_mold)
  faltas_envelhecimento = envelhecimento(ref, num_mold)
  return faltas_fifo, faltas_envelhecimento

from gaussiana import gerar_rastro_acesso

rastro_do_processo = gerar_rastro_acesso()
def analise(num_molduras):
  faltas = simular(rastro_do_processo, num_molduras)
  print(faltas)
  return faltas

with open("resultados.txt", 'w', encoding='utf-8') as f:  
    for i in range(100):
        resultado = analise(i+1)
        f.write(f" {resultado},\n")


save_logs_to_file(rastro_do_processo, global_logs)