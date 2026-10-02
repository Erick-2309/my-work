import random as r

#DS Python GPSE S6
#Ralph Mansour

#Exercice 1

def generer_matrice(n, m):
    return [[r.randint(0, 10) for i in range(m)] for j in range(n)]

    
def compte_cinq(matrice):
    compte = 0
    for ligne in matrice:
        for val in ligne:
            if val > 5:
                compte += 1
    return compte


def matrice_binaire(matrice):
    return [[1 if val >= 5 else 0 for val in ligne] for ligne in matrice]


def compte_zeros_uns(matriceB):
    compte_zeros = 0
    compte_uns = 0
    for ligne in matriceB:
        compte_zeros += ligne.count(0)
        compte_uns += ligne.count(1)
    return compte_zeros, compte_uns



#Tests

n, m = 5, 4
M = generer_matrice(n, m)

print("Matrice générée :")
for ligne in M:
    print(ligne)

count_above_five = compte_cinq(M)
print(f"Nombre de valeurs supérieures à 5 : {count_above_five}")

Mbinaire=matrice_binaire(M)   
print("La matrice contenant uniquement des 0 et des 1 : ")
for ligne in Mbinaire:
    print(ligne)    
    
count_zeros, count_ones = compte_zeros_uns(Mbinaire)
print(f"Nombre de 0 : {count_zeros}")
print(f"Nombre de 1 : {count_ones}")