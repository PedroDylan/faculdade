notas_classe = []
numero_alunos = 1
for i in range(numero_alunos):
    notas_aluno = []
    for i in range(3):
        x = float(input("Insira uma nota semestral: "))
        notas_aluno.append(x)
    notas_classe.append(notas_aluno)


def calcula_media_aluno(lista):
    sum = 0 
    for x in lista:
        sum += x
    return sum/3

def calcula_media_turma(lista):
    sum = 0
    for x in lista:
        sum += calcula_media_aluno(x)
    return sum/numero_alunos
      
def situacao_acad(lista):
    if calcula_media_aluno(lista) >= 7:
        return "Aprovado"
    elif 4 <= calcula_media_aluno(lista) <= 6.9:
        return "AF"
    else:
        return "Reprovado"


print(notas_classe)
print(calcula_media_turma(notas_classe))
for x in notas_classe:
    print(situacao_acad(x))
