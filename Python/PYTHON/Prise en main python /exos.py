
"""
Exercice 1
Prise en main
Écrivez un programme qui convertit un nombre entier de secondes fourni au départ en 
un nombre d’années, de mois, de jours, de minutes et de secondes 
(utilisez l’opérateur modulo : %)

"""

def conversion(seconde):
    annee = seconde // (12*365*24*3600)
    secondes_restantes=seconde % (12*365*24*3600)
    
    mois = secondes_restantes // (30*24*3600)
    secondes_restantes=secondes_restantes % (30*24*3600)
    
    
    jours = secondes_restantes // (24*3600)
    secondes_restantes = secondes_restantes % (24*3600)
    
    heure = secondes_restantes // 3600
    secondes_restantes = secondes_restantes % (3600)
    
    minutes = secondes_restantes // 60
    secondes_restantes = secondes_restantes  % 60  # Reste pour obtenir les secondes

    #print(f"{seconde} secondes = {minutes} minutes et {secondes_restantes} secondes")
    print("\n",annee,"ans","\n",mois,"moisde 30 jours","\n",jours,"jours","\n",heure,"heure","\n",minutes,"minute ","\n ",secondes_restantes,"seconde")

seconde = int(input("Entrez le nombre de secondes : "))
conversion(seconde)

"""
Exercice 2
Écrivez un programme qui affiche les 20 premiers termes de la table de multiplication par 7, en signalant au passage (à l’aide d’une astérisque) ceux qui sont des multiples de 3.
Exemple : 7 14 21 * 28 35 42 * 49
"""
def multiplie():
    for i in range(20):
        if(7*i%3==0):
            a=print(7*i,"*")
        else:
            print(7*i)
        
multiplie()


"""
Exercice 3
Écrivez un programme qui calcule les 50 premiers termes de la table de multiplication par 13, mais n’affiche que ceux qui sont des multiples de 7.
"""
def multiple_13():
    for i in range(50):
        if(13*i%7==0):
            print(13 * i, end=", ")


multiple_13()

"""
Exercice 4
Écrivez un programme qui affiche la suite de symboles suivante : *
**
***
****
*****
******
*******
"""
def triangle(n):
    for i in range(1,n):
        for j in range(i):
            print(f"* ",end="")
        print('\n')
triangle(7)
