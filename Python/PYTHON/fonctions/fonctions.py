"""
Exercice 1
Écrire une fonction ChangeCar(chaine,ch1,ch2,debut,fin) qui remplace 
tous les caractères ch1 par des caractères ch2 dans la chaîne de caractères chaine,
à partir de l’indice debut et jusqu’à l’indice fin. Si les deux derniers arguments sont omis, 
dans ce cas la chaîne est traitée d’une extrémité à l’autre.
Testez.
"""

def ChangeCar(chaine,ch1,ch2,debut=0,fin=-1):
     if fin==-1:
          fin=len(chaine)
     new_chaine=""
     i=0
     while i<len(chaine):
        if(i>=debut and i<=fin and chaine[i]==ch1):
           new_chaine=new_chaine+ch2
        else:
            new_chaine=new_chaine+chaine[i]
        i=i+1
     return new_chaine
#test
print (ChangeCar("Ceci est une chaîne de caractères", "  ", " * "))
print (ChangeCar("Ceci est une chaîne de caractères", " ", "*", 8, 12))
print (ChangeCar("Ceci est une chaîne de caractères", " ", "*", 12))


"""
Exercice 2
Écrire une fonction EleMax(liste,debut,fin) qui renvoie l’élément ayant la plus grande valeur dans la liste transmise. 
Les deux arguments debut et fin indiqueront les indices entre lesquels doit être effectué la recherche. 
Si les deux derniers arguments sont omis dans ce cas la liste est traitée d’une extrémité à l’autre.
Testez."
"""
def EleMax(liste,debut=0,fin=-1):
    if fin==-1:
        fin=len(liste)
    i=0
    M=0
    for i in range(debut,fin):
        if liste[i]>M:
            M=liste[i]
    return M
#test
L=[4,1,12,3,32,4,34,34,22,2,5,67]
print(EleMax(L,0,5))


"""
Exercice 3
Écrire une fonction Swap(a, b) permettant de permuter les valeurs des deux variables a et b. Testez.
"""
def Swap(a, b):
    if(a!=b):
        a,b=b,a
    else:
        print(a,"et ",b,"sont identique")
    return a,b
#test
print(Swap(4,3))
a = 10
b = 20
print(a,b)
a, b = Swap(a,b)
print(a,b)

"""
Exercice 4
Écrire une fonction Factorielle(n) retournant le factoriel du nombre n. Teste
"""
def Factorielle(n):
     if n == 0:
        return 1
     i=1
     F=1
     while i<=n:
        F=F*i
        i=i+1
     return F
#test
print(Factorielle(0))
print(Factorielle(3))
print(Factorielle(5))

"""
Exercice 5
Écrire une fonction Premier(nombre) retournant un booléen permettant de déterminer si nombre est premier ou non.
Testez.
"""
def Premier(n):
    P=True
    for i in range(2,n):
         if n%i==0:
             P=False
    return P
#test
N=int(input("etrez un nombre"))
if Premier(N)==True:
    print(N,"est premier")
else:
     print(N,"n'est premier")

print(Premier(6))

"""
Exercice 6
Écrire une fonction ValeurPoly(x, n, Coef) permettant d’évaluer la valeur 
d’un polynôme (en x) à n coefficients saisis par l’utilisateur. 
Les coefficients seront saisis dans le tableau Coef . Testez
"""
"""
def ValeurPoly(x, n, Coef) :
    n=int(input("entrez le nombre de coef"))
    coef=[]
    c=0
    result=0
    for i in range(n):
       c=int(input("entrez le coef ",i,":",coef[i],"\n"))
       coef.append(c)
    print(coef)
    x=int(input("entrez la valeur de x"))
    for i in range(0,n-1):
         result=result+coef[i]*x**n-i 
    return result

coef=[]
print(ValeurPoly(2,3,coef))
"""

# Exo 6
import  numpy as np

def polynome(x,n,coef):
    "Calcul la valeur d'un polynome de degré n en x, cef: coefficiens du polynôme"
    "a0 + a1*x + a2*x^2 + a3*x^3 + ... + an-1*x^(n-1)"
    val = 0    
    for i in range(n-1,0,-1):
        val = val + coef[i]*x**i
    val = val + coef[0]
    return val

# test
coef = np.array([1, 2, 3, 4, 5])
print(polynome(0,5,coef))
print(polynome(1,5,coef))
print(polynome(2,5,coef))


"""
 Exercice 7
Écrire une fonction Pi(x, n, Coef) permettant d’évaluer une valeur approchée de
 p à l’aide de la formule de Leibniz : Testez.
 Testez.
"""
def Pi(n):
    val =0 
    for i in range(0,n):
        val=val+ 4*((-1)**i/(2*i+1))

    return val

print(Pi(100))
print(Pi(1000))