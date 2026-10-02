#Exo 1:

# convertit un nombre entier de secondes fourni au départ en un
# nombre d’années, de mois, de jours, de minutes et de secondes

# Le nombre de secondes est fourni au départ :
# (un grand nombre s'impose !)
nsd = 12345678912

# Nombre de secondes dans une journée :
nspj = 3600 * 24

# Nombre de secondes dans un an (soit 365 jours -
# on ne tiendra pas compte des années bissextiles) :
nspa = nspj * 365

# Nombre de secondes dans un mois (en admettant
# pour chaque mois une durée identique de 30 jours) :
nspm = nspj * 30

# Nombre d'années contenues dans la durée fournie :
na = nsd / nspa # division <entière>
nsr = nsd % nspa # n. de sec. restantes

# Nombre de mois restants :
nmo = nsr / nspm # division <entière>
nsr = nsr % nspm # n.

nj = nsr / nspj # division <entière>
nsr = nsr % nspj # n. de sec. restantes

# Nombre d'heures restantes :
nh = nsr / 3600 # division <entière>
nsr = nsr % 3600 # n. de sec. restantes

# Nombre de minutes restantes :
nmi = nsr /60 # division <entière>
nsr = nsr % 60 # n. de sec. restantes
print ("Nombre de secondes . convertir :", nsd)
print ("Cette durée correspond .", na, "années de 365 jours, plus")
print (nmo, "mois de 30 jours,",)
print (nj, "jours,",)
print (nh, "heures,",)
print (nmi, "minutes et",)
print (nsr, "secondes.")

---------------------------------------------------------------------
#Exo 2
# affichage des 20 premiers termes de la table par 7,
# avec signalement des multiples de 3 :

i = 1 # compteur : prendra successivement les valeurs de 1 à 20
while i < 21:
    # calcul du terme à afficher :
    t = i * 7
    # affichage sans saut à la ligne (utilisation de la virgule) :
    print (t,'  ',end='')       # affichage sans retout à la ligne
    # ce terme est-il un multiple de 3 ? (utilisation de l'opérateur modulo) :
    if t % 3 == 0:
        print ('*',end='')      # affichage d'une astérisque dans ce cas
    i = i + 1                   # incrémentation du compteur dans tous les cas

---------------------------------------------------------------------
#Exo 3
# calcule les 50 premiers termes de la table de multiplication par 13,
# mais n’affiche que ceux qui sont des multiples de 7


i = 1 # compteur : prendra successivement les valeurs de 1 à 50
while i < 51:
    # calcul du terme à afficher :
    t = i * 13
    # ce terme est-il un multiple de 7 ? (utilisation de l'opérateur modulo) :
    if t % 7 == 0:
        print (t,'  ',end='')    # affichage d'une astérisque dans ce cas
    i = i + 1               # incrémentation du compteur dans tous les cas

---------------------------------------------------------------------
#Exo 4
# affiche une suite d'astérisques avec retour à la ligne

nba = 7     # nombre astérisques de la dernière ligne
nbal = 1    # nombre astérisques par ligne
for i in range (nba): 
    for i in range (nbal):
        print ('*', end='')
    print('Oranges_r')
    nbal =  nbal + 1

