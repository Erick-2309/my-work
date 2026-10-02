
# Exo 1
# Combinaison de deux listes en une seule

def List(t1,t2):
    t1 = [31,28,31,30,31,30,31,31,30,31,30,31]
    t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']

    t3=[]
    for i in range(len(t2)):
         t3.append(t2[i])
         t3.append(t1[i])
    print(t3)
t1 = [31,28,31,30,31,30,31,31,30,31,30,31]
t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
List(t1,t2)

"""
Exercice 2
Écrivez un programme qui affiche « proprement » tous les éléments d’une liste. Si on l’appliquait par exemple à la liste t2 de l’exercice 1, on devrait obtenir :
"""
def affiche(t2):
     t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
     for i in range (len(t2)):
          print(t2[i],end=" ")
t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
affiche(t2)

"""
Exercice 3
Écrivez un programme qui recherche le plus grand et le plus petit éléments présents dans une liste donnée.

"""
def recherche(t2):
     t2 =['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
     petit=t2[0]
     lon=t2[0]
     for i in range(len(t2)):
          if(len(t2[i])<=len(petit)):
               petit=t2[i]
          elif(len(t2[i])>=len(lon)):
               lon=t2[i]
     print("\n","le plus petit est: ",petit,"et le plus long est: ",lon)
t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
recherche(t2)

"""
Exercice 4
Écrivez un programme permettant d’extraire les éléments pairs et impairs contenus dans une liste et les stocks dans deux listes différentes.

"""
def extraire(t3):
     t3 = [31,28,31,30,31,30,31,31,30,31,30,31]
     T1=[]
     T2=[]
     i=0
     while i<len(t3):
          if(t3[i]%2==0):
               T1.append(t3[i])
          else:
               T2.append(t3[i])
          i=i+1
     print("paire: ",T1,"\nimpaire:",T2)
t3 = [31,28,31,30,31,30,31,31,30,31,30,31]
extraire(t3)

"""
Exercice 5
Écrivez un programme qui analyse un par un tous les éléments d’une liste de mots pour générer deux nouvelles listes. L’une contenant les mots comportant moins de 6 caractères,
l’autre les mots comportant 6 caractères ou davantage.
"""
def analyse(t2):
     t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']
     T1=[]
     T2=[]
     for i in range(len(t2)):
          if(len(t2[i])<6):
               T1.append(t2[i])
          else:
               T2.append(t2[i])
     print("mion de 6: ",T1,"\nsupérieur ou egale a 6:",T2)  

t2 = ['Janvier','Février','Mars','Avril','Mai','Juin',
            'Juillet','Août','Septembre','Octobre','Novembre','Décembre']   
analyse(t2)

"""
Exercice 6
Soit la liste suivante :
['Jean-Michel', 'Marc', 'Vanessa', 'Anne', 'Maximilien', 'Alexandre-Benoît', 'Louise']
Écrivez un programme qui affiche chacun de ces noms avec le nombre de caractères correspondant.
"""
def caractèer(T):
     T=['Jean-Michel', 'Marc', 'Vanessa', 'Anne', 'Maximilien', 'Alexandre-Benoît', 'Louise']
     for i in range(len(T)):
        print(T[i],len(T[i]))
T=['Jean-Michel', 'Marc', 'Vanessa', 'Anne', 'Maximilien', 'Alexandre-Benoît', 'Louise']
caractèer(T)

"""
Exercice 7
Écrire une boucle de programme qui demande à l’utilisateur d’entrer des notes d’élèves. La boucle se terminera seulement si l’utilisateur entre une valeur négative. Avec les notes ainsi entrées, construire progressivement une liste. Après chaque entrée d’une nouvelle note (et donc à chaque itération de la boucle), afficher le nombre de notes entrées, la note la plus élevée, la note la plus basse, la moyenne de toutes les notes.
"""

def note():
     t=[]
     print("entre les notre ici")
     notes=input()
    # t.append(notes)
     t = list(map(int, notes.split()))  
     print(len(t),max(t),min(t))
     moy=0
     somme=0
     for i in range(len(t)):
          somme=somme+t[i]
     moy=somme/len(t)
     print(moy)       
note()


def notes():
     t=[]
     note= "start"  # valeur quelconque (mais non nulle)
     somme=0
     moy=0
     L=0 #  nombre de note

     while note!="":   # Tant que l'utilisateur ne saisit pas une chaîne vide   
          note=input("entrez la note")
          if note!=" ": # Vérifie si l'utilisateur n'a pas appuyé directement sur Entrée
               t.append(float(note)) # Convertit la note en float et l'ajoute à la liste
               somme=somme+t[L]# Ajoute la dernière note à la somme totale
               L=L+1
               moy=somme/L
          print("nombre de note: ",L,"max: ",max(t),"min: ", min(t), "moyenne: ",moy)
notes()              

