#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May  5 10:07:25 2021

@author: rjennane
"""
##--------------------------------------------------------------------
# Exo1
# Recherche d'un caractère particulier dans une chaîne
# Chaîne fournie au départ :
ch = "Bonjour Polytech"

# Caractère . rechercher :
cr = "e"

# Recherche proprement dite :
lc = len(ch)    # nombre de caractères à tester
i = 0           # indice du caractère en cours d'examen
t = 0           # "drapeau" à modifier si le caractère recherche est présent

while i < lc:
    if ch[i] == cr:
        t = 1
    i = i + 1

# Affichage :
print ("\nLe caractère", "'",cr, "'" , end='')
if t == 1:
    print ("est présent", end='')
else:
    print ("n'est pas ", end='')
print ("dans la chaîne", "'",ch,"'", end='')

##--------------------------------------------------------------------
# Exo2
# Compte le nombre d’occurrences du caractère « o » dans une chaîne
# Chaîne fournie au départ :
ch = "Bonjour Polytech"

# Caractère à rechercher :
cr = "o"

# Recherche proprement dite :
lc = len(ch)    # nombre de caractères à tester
i = 0           # indice du caractère en cours d'examen
cpt = 0         # compteur

while i < lc:
    if ch[i] == cr:
        cpt = cpt + 1   
    i = i + 1

# Affichage :
print ("\nLe caractère", "'",cr,"'", "est présent dans la chaine","'",ch,"'",cpt,"fois")
##--------------------------------------------------------------------
# Exo3
# Insertion d'un caractère '*' dans une chaîne
ch = "toto"
# Caractère à insérer :
cr = "*"

# Le nombre de caractères à insérer est inférieur d'une unité au
# nombre de caractères de la chaîne. On traitera donc celle-ci à
# partir de son second caractère (en omettant le premier).
lc = len(ch)     # nombre de caract.res total
i = 1            # indice du premier caractère à examiner (le second, en fait)
nch = ch[0]      # nouvelle chaîne à construire (contient déjà le premier car.)
while i < lc:
    nch = nch + cr + ch[i]
    i = i + 1

# Affichage :
print (nch)

##--------------------------------------------------------------------
# Exo4
# Inversion d'une chaîne de caractères
# Chaîne fournie au départ :
ch = "burgos"
lc = len(ch)    # nombre de caractères total
i = lc - 1      # le traitement commencera . partir du dernier caractère
nch = ""        # nouvelle chaîne à construire (vide au départ)

while i >= 0:
    nch = nch + ch[i]
    i = i - 1

# Affichage :
print (nch)

##--------------------------------------------------------------------
# Exo5
# Détermine si une chaîne de caractères est un plaindrome
# Chaîne fournie au départ :
ch = "radar"

lc = len(ch)    # nombre de caractères total
pal = 1
i = 0

while i < lc:
    if (ch[i] != ch[lc-i-1]):
        pal = 0
    i = i + 1

# Affichage :
if (pal == 1):
    print(ch, "est un palindrome")
else:
    print(ch, "n'est pas un palindrome")