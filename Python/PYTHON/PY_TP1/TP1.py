#In [1]:
message = 'Hello'
print(message)

#In [1]:
n=23
mess1 = "Il dit : \n 'bonjour, nous sommes" 
mess2 = "personnes'"
print(mess1, n, mess2)
print(n)
print(mess1+mess2)

#In [3]:
print(0.2+0.1)


etudiants = ['Azzedine', 'Balla', 'Baptiste', 'Brahim' ]
nums = [1,2,5,-6,4,5,8,9]
#In [6]:
L = ['bonjour', 4,3]
print(L)

#In [7]:
print(nums)
print(etudiants)
  
#In [8]:
for etu in etudiants :
      print('Hello '+etu)
#In [9]:
for n in nums : print(n**2)
 


#In{10}
print(etudiants[0])
print(etudiants[-1])
print(nums[2])
print(nums[-4])

#In [11]:
for i,etu in enumerate(etudiants):
    print(etu, i)
    
#In [11]:
nums[4] = -10
print(nums)


etudiants.append('Toto')
print(etudiants)

print(etudiants.index('Toto'))
print('Toto' in etudiants) #verifie si toto est dans la liste des etudiants 
print('Toto1' in etudiants)
etudiants.insert(3,'intrus')
print(etudiants)


L1 = []
print(L1)
print(nums)
nums2 = nums
nums2[0] = -5
print(nums2)
print(nums)
nums3 = nums.copy()
nums3[0] = -50
print(nums3)
print(nums)
A = sorted(etudiants)
print(A)
print(etudiants)


print(nums3)
nums3.reverse()
print(nums3)
print(len(etudiants))
print(len(nums))


print(etudiants) 
del etudiants[3] 
print(etudiants)

print(etudiants)
etudiants.remove('Toto')
print(etudiants)

print(nums)
nums.remove(5)
print(nums)

L1 = etudiants[1:3]
print(L1)

L2 = etudiants[-2:]
print(L2)

L3 = etudiants[:4]
print(L3)

for n in range(5):
    print(n)

print("  ")

for n in range(5, 20, 3):
    print(n)
    
N = list(range(5, 20, 3))
print(N)

carres = [i**2 for i in range(1,11)] 
print(carres)

M1 = ['prenom = '+etu for etu in etudiants]
print(M1)



T=(1,3,-2,5,1)
print(T)
print(T[1])
T2 = ('a', 'b', 'c')
print(T2)
u,v=10,11 
print(u)
print(v)


u, v = v+1, u+1
print(u,v)
a=1
b=2 
a,b=b,a
print(a,b)


#un dictionnaire 
mondic={'etu1':'chat', 'etu2':'chien', 'etu3':'poisson'}
print(mondic)

for cle, val in mondic.items(): 
    print(cle, val)
 

D = {}
D["nom"] = "Lucas"
D["prenom"] = "Carine"
print(D)
for c in D.keys(): 
    print(c)
for v in D.values(): 
    print(v)

"""
Exemple d'utilisation : un dictionnaire pour transcrire les bases de l'adn
 A devient U
 T devient A
 G devient C 
 C devient G
Commande pour connaître le type d'objet
"""

print(type(nums)) 
print(type(T)) 
print(type(D))

"""
4 - Boucles while
syntaxe ( : et indent)
variable à initialiser et à modifier
"""
k=2
while k<10 :
    k = k+1
    print(k-1)



k=2 
i=5
while k<10 and i> 0: 
    print(k,i)
    k = k+1 
    i = i-1

k=2 
i=5
while k<10 or i> 0:
    print(k,i)
    k = k+1 
    i = i-1
 
"""
Exercice : Écrire une boucle while en itinialisant n à 8 
et en faisant diminuer n de 3 à chaque étape tant que n est positif ou nul.
 A la fin de la boucle, afficher la valeur de n.
 """


n=8 
while n>=0:
    print(n)
    n=n-3 
    
   
n = float(input('nombre =')) 
if n > 0 :
  print('le nombre est positif') 
else :
  print('le nombre est négatif ou nul')


"""
Exercice : Recopier la cellule précédente et modifier 
les commandes pour afficher un message différent lorsque n est 
compris entre 0 et 10.
"""
   
n = float(input('nombre =')) 
if (n >=0 and n<=10):
  print('le nombre est compris entre 0 et 10') 
else :
  print('le nombre est négatif ou nul')

"""
Exercice : En parcourant tous les entiers entre 0 et 20,
 afficher les multiples de 3 (la commande '%' renvoie le modulo)
"""

for i in range(0,20): 
    if i%3==0:
      print(i,"est multiple")
      
      
def essai(p1, p2, p3): 
    return p1+2*p2-3*p3
print(essai(1,4,5))

def essai2(p1, p2, p3): 
    return p1+2*p2-3*p3, p1**2

S = essai2(1,4,5) 
print(S)
print(type(S))
print(S[0])
print(S[1])

"""
Exercice : Écrire une fonction discretisation qui prend 3 nombres en paramètres 
a, b et n et qui renvoie la liste contenant 
l'intervalle [a,b] discrétisé en n intervalles : [a, a+dx , ... b-dx, b].
Vérifier que la liste obtenue par exécution de la fonction contient bien n+1 points
"""

def discretisation(a,b,n):
    dx=(a+b)/2
    point=[a+j*dx for j in range(n)]
    return point 
print(discretisation(10, 10,5))
    















