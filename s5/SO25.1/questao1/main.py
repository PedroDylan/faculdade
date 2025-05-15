from Processo import generate_process, Processo
from FirstComeFirstServe import fcfs
from RoundRobin import round_robin
from ShortestJobFirst import sjf_nao_preemptivo
from Metricas import calcular_metricas

#Número de processos 
N = 5
processos = generate_process(N)
quantums = [2,5,10]

print("Processos gerados:")
print("ID | Chegada | Burst")
for p in processos:
    print(f"{p.id:3} | {p.chegada:7} | {p.burst_time:5}")


#simular FCFS
fcfs_resultado = fcfs(processos)
fcfs_metricas = calcular_metricas(fcfs_resultado)

#simular sjf
sjf_resultado = sjf_nao_preemptivo(processos)
sjf_metricas = calcular_metricas(sjf_resultado)

#simular rr por quantum
rr_metricas = {}
for q in quantums:
    rr_resultado = round_robin(processos,q)
    rr_metricas[q] = calcular_metricas(rr_resultado)


# Exibir resultados
    print("\nMétricas:")
    print("Algoritmo | Avg Waiting (std) | Avg Turnaround (std) | Throughput")
    print(f"FCFS      | {fcfs_metricas['media_espera']:.2f} (±{fcfs_metricas['desvio_espera']:.2f}) | {fcfs_metricas['media_retorno']:.2f} (±{fcfs_metricas['desvio_retorno']:.2f}) | {fcfs_metricas['throughput']:.2f}")
    print(f"SJF       | {sjf_metricas['media_espera']:.2f} (±{sjf_metricas['desvio_espera']:.2f}) | {sjf_metricas['media_retorno']:.2f} (±{sjf_metricas['desvio_retorno']:.2f}) | {sjf_metricas['throughput']:.2f}")
    for q in quantums:
        print(f"RR (q={q}) | {rr_metricas[q]['media_espera']:.2f} (±{rr_metricas[q]['desvio_espera']:.2f}) | {rr_metricas[q]['media_retorno']:.2f} (±{rr_metricas[q]['desvio_retorno']:.2f}) | {rr_metricas[q]['throughput']:.2f}")