#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue May  4 09:14:09 2021
@author: rjennane
"""
A=int(input("entre une valeur "))
print(A)

#TP6, listes
##---------------------------------------------------------------------
# Exo 1
# Combinaison de deux listes en une seule
# Listes fournies au départ :
t1 = [31,28,31,30,31,30,31,31,30,31,30,31]
t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
'Juillet','Août','Septembre','Octobre','Novembre','Décembre']

# Nouvelle liste à construire (vide au départ) :
t3 = []

# Traitement :
i = 0

while i < len(t1):
    t3.append(t2[i])
    t3.append(t1[i])
    i = i + 1

# Affichage :
print (t3)

##---------------------------------------------------------------------
#Exo 2
# Affichage des éléments d'une liste
i = 0
while i < len(t2):
    print (t2[i]," ", end='')
    i = i+1
    
##---------------------------------------------------------------------
# Exo 3
# Recherche du plus grand et du plus petit élément d'une liste
# Liste fournie au d.part :
lst = [32, 5, 12, 8, 3, 75, 2, 15]

max = lst[0]
min = lst[0]

i = 0
while i < len(lst):
    if lst[i] > max:
        max = lst[i]    # nouveau maximum
    if lst[i] < min:
        min = lst[i]    # nouveau minimum
    i = i + 1

# Affichage :
print ("\nLe plus grand élément de la liste est : ", max)
print ("Le plus petit élément de la liste est : ", min)

##---------------------------------------------------------------------
# Exo 4
# Sépration des nombres impairs et pairs d'une liste
lst = [32, 5, 12, 8, 3, 75, 2, 15]

pairs = []
impairs = []

i = 0
while i < len(lst):
    if lst[i] % 2 == 0:
        pairs.append(lst[i])
    else:
        impairs.append(lst[i])
    i = i + 1

# Affichage :
print ("Nombres pairs :", pairs)
print ("Nombres impairs :", impairs)

##---------------------------------------------------------------------
# Exo 5
# Sépration d'une liste de mots en 2 listes de mots comportant moins 
# de 6 caractères, # l’autre les mots comportant 6 caractères ou davantage
lst = ['Janvier','Février','Mars','Avril','Mai','Juin',
'Juillet','Août','Septembre','Octobre','Novembre','Décembre']

Lt6Car = []
Mt6Car = []

i = 0
while i < len(lst):
    if len(lst[i]) < 6:
        Lt6Car.append(lst[i])
    else:
        Mt6Car.append(lst[i])
    i = i + 1

# Affichage :
print ("Liste des mots de moins de 6 caactères :", Lt6Car)
print ("Liste des mots de plus de 6 caactères :", Mt6Car)

##---------------------------------------------------------------------
# Exo 6
# affiche chacun des noms avec le nombre de caractères correspondant
lst = ['Jean-Michel', 'Marc', 'Vanessa', 'Anne', 'Maximilien',
         'Alexandre-Benoît', 'Louise']

# Affichage
i = 0
while i < len(lst):
    print (lst[i],len(lst[i]))
    i = i+1
    
##---------------------------------------------------------------------
# Exo 7
# Saisie notes, calcul et affichage moyenne
notes = []          # Liste à compléter (vide au départ)

ch = "start"        # valeur quelconque (mais non nulle)
nbn = 0
moy = 0

while ch != "":
    ch = input ("Veuillez entrer une note : ")
    if ch != "":
        notes.append(float(ch))    # variante : tt.append(ch)
        moy = moy + notes[nbn]
        nbn = nbn + 1
        print ("Nombre de notes :", nbn," ", "Notes :",  notes, "Moyenne =",moy/nbn)
