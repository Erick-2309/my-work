#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May  5 08:50:33 2021

@author: rjennane
"""
##--------------------------------------------------------------------
# Exo1
def changeCar(ch, ca1, ca2, debut =0, fin =-1):
    "Remplace tous les caractères ca1 par des ca2 dans la chaîne ch"
    if fin == -1:
        fin = len(ch)

    nch, i = "", 0      # nch : nouvelle chaîne à construire

    while i < len(ch) :
        if i >= debut and i <= fin and ch[i] == ca1:
            nch = nch + ca2
        else :
            nch = nch + ch[i]
        i = i + 1
    return nch

# test

print (changeCar("Ceci est une chaîne de caractères", " ", "*"))
print (changeCar("Ceci est une chaîne de caractères", " ", "*", 8, 12))
print (changeCar("Ceci est une chaîne de caractères", " ", "*", 12))

##--------------------------------------------------------------------
# Exo 2
def EleMax(lst, debut =0, fin =-1):
    "renvoie le plus grand .l.ment de la liste lst"
    if fin == -1:
        fin = len(lst)

    max, i = 0, 0
    while i < len(lst):
        if i >= debut and i <= fin and lst[i] > max:
            max = lst[i]
        i = i + 1
    return max


# test
serie = [91, 13, 6, 11, 7, 5, 4, 80, 2]
print(EleMax(serie))
print(EleMax(serie, 2))
print(EleMax(serie, 2, 5))

##--------------------------------------------------------------------
# Exo 3
def Swap(val1,val2):
    "permute deux éléments"
    val1, val2 = val2, val1
    return val1, val2

# test
a = 10
b = 20
print(a,b)
a, b = Swap(a,b)
print(a,b)

##--------------------------------------------------------------------
# Exo 4
def factoriel(n):
    "Calcul la valeur factorielle de n"
    if n == 0:
        return 1
    else:
        fact = 1
        for i in range(2,n+1):
            fact = fact * i
        return fact

# test
print(factoriel(0))
print(factoriel(3))
print(factoriel(4))
print(factoriel(5))
print(factoriel(6))
print('\n')

# autrement
def factorielle(n):
    if n == 0:
        return 1
    else:
        return n  * factorielle(n-1)

# test
print(factorielle(0))
print(factorielle(3))
print(factorielle(4))
print(factorielle(5))
print(factorielle(6))

##--------------------------------------------------------------------
# Exo 5
def premier(nbr):
    "Détermine si nbr est premier"
    i = 2
    while (i < nbr) and (nbr % i != 0):
        i = i + 1
    if i == nbr:
        return 1
    else:
        return 0
    
# test
n = int(input("Entrer un nombre : "))

if premier(n) == 1:
    print(n, "est premier")
else:
    print(n, "n'est pas premier")  
    
##--------------------------------------------------------------------
# Exo 6
import  numpy as np

def polynome(x,n,coef):
    "Calcul la valeur d'un polynome de degré n en x, cef: coefficiens du polynôme"
    "a0 + a1*x + a2*x^2 + a3*x^3 + ... + an-1*x^(n-1)"
    val = 0    
    for i in range(n-1,0,-1):
        val = val + coef[i]*x
    val = val + coef[0]
    return val

# test
coef = np.array([1, 2, 3, 4, 5])
print(polynome(0,5,coef))
print(polynome(1,5,coef))
print(polynome(2,5,coef))

##--------------------------------------------------------------------
# Exo 7
def pi(n):
    "Valeur approchée de pi par la formule de Leibnitz"
    val = 0    
    for i in range(0,n):
        val = val + (-1)**i/(2*i+1)
    val = val * 4
    return val

# test
print(pi(100))
print(pi(1000))