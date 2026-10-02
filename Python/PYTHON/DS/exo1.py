
import random as r

#DS Python GPSE S6


#Exercice 1

def generer_matrice(n, m):
    return [[r.randint(0, 20) for i in range(m)] for j in range(n)]

        
def compter_sup_10(matrice):
    compte = 0
    for ligne in matrice:
        for val in ligne:
            if val > 1:
                compte += 1
    return compte

def matrice_binaire(matrice):
    return [[1 if val >= 10 else 0 for val in ligne] for ligne in matrice]



n, m = 5, 4
M = generer_matrice(n, m)

print("Matrice originale :")
for ligne in M:
    print(ligne)

count_above_dix = compter_sup_10(M)
print(f"Nombre de valeurs supérieures à 10 : {count_above_dix}")

Mbinaire=matrice_binaire(M)   
print("La matrice contenant uniquement des 0 et des 1 : ")
for ligne in Mbinaire:
    print(ligne)    


def transposee(matrice):
    return [[matrice[j][i] for j in range(len(matrice))] for i in range(len(matrice[0]))]


# test 
matrice = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print("Matrice originale :")
for ligne in matrice:
    print(ligne)

print("Matrice transposée :")
transpose = transposee(matrice)
for ligne in transpose:
    print(ligne)

print("Matrice 2transposée :")
transpose_2 = transposee(transpose)
for ligne in transpose_2:
    print(ligne)
