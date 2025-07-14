import numpy as np
import random

def gerar_referencia_numpy(num_total_paginas_logicas, centro, desvio):

    referencia_continua = np.random.normal(loc=centro, scale=desvio)
    pagina_acessada = int(round(referencia_continua))
    pagina_acessada = max(0, min(pagina_acessada, num_total_paginas_logicas - 1))
    return pagina_acessada

def gerar_rastro_acesso(num_total_paginas_logicas=26, centro_inicial=3, desvio=1,
                         passo_inicial=0.2, total_ref=5000):
   
    centro_atual = float(centro_inicial)
    passo_atual = float(passo_inicial)
    acessos = []

    mapeamento_pagina_para_representacao = {i: chr(65 + i) for i in range(num_total_paginas_logicas)}

    print(f"\n--- Gerando Rastro de Acesso para {num_total_paginas_logicas} Páginas Lógicas (A-Z) ---")
    print(f"Configurações do Conjunto de Trabalho: Centro Inicial={centro_inicial}, Desvio={desvio}, Passo={passo_inicial}, Total Referências={total_ref}")

    for _ in range(total_ref):
        pagina_acessada_numero = gerar_referencia_numpy(num_total_paginas_logicas, centro_atual, desvio)
        
        pagina_acessada_string = mapeamento_pagina_para_representacao[pagina_acessada_numero]
        acessos.append(pagina_acessada_string)

        limite_inferior_movimento = desvio * 0.5 
        limite_superior_movimento = num_total_paginas_logicas - 1 - desvio * 0.5 

        centro_atual += passo_atual

        if centro_atual > limite_superior_movimento:
            centro_atual = limite_superior_movimento
            passo_atual *= -1
        elif centro_atual < limite_inferior_movimento:
            centro_atual = limite_inferior_movimento
            passo_atual *= -1

    print(f"--- Geração do Rastro Concluída. Centro final: {centro_atual:.2f} ---")
    return acessos

if __name__ == "__main__":
    rastro_do_processo = gerar_rastro_acesso()

    print("\n--- AMOSTRA DO RASTRO DE ACESSO GERADO (primeiros 200 acessos) ---")
    print(rastro_do_processo[:200])