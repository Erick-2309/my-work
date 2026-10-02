import numpy as np
import matplotlib.pyplot as plt
import scipy.optimize as op  
import scipy.linalg as la

#In [2]:
print(np.sqrt(4))
#In [3]: 
print(np.cos(np.pi/2)) 

print(np.exp(5))

liste = [1,3,4,5]
print(liste)

tab = np.array(liste)
print(tab)

print(type(liste), type(tab))

print(tab[0])
print(tab[1:3])
print(" ")
print("unstruction suivante")
tab2d = np.array([ [1,2], [3,4], [5,6] ])
print(tab2d)
print(len(tab2d))
print(tab2d.ndim) 
print(tab2d.shape) #forme (3,2) 3ligne 2 colonne
print("unstruction suivante")
print(tab2d[0,0])
print(tab2d[0,:]) # première ligne 
print(tab2d[1,:]) # deuxième ligne 
print(tab2d[2,:])
print(tab2d[:,0]) # première colonne  
print(tab2d[:,1]) # deuxième colonne 
print("unstruction suivante")
x = np.arange(0.0,2.1,0.1) # de 0 à 2.1 ecart de 0.1
print(x)
print(type(x))
print("unstruction suivante")
y = np.linspace(0,2, 10) # de 0 à 2 un tableau de 21 élements
print(y)
print(type(y))
print(y[2])
print("unstruction suivante")
A = np.array([ [1,2,3] , [4,5,6] , [6,7,8] ]) 
print(A)
print("unstruction suivante B = 2*A")
B = 2*A
print(B)
print("unstruction suivante C = A+B")
C = A+B
print(C)
print("unstruction suivante A*B produit element par element ")
print(A*B)  #fait le produit element par element 
print("unstruction suivante dot(A,B) produit matriciel")
print(np.dot(A,B))  # fait le produit matriciel
print("unstruction suivante A@B produit matriciel")
print(A@B)  # fait le produit matriciel
print("unstruction suivante")
v = np.array([0,1,2])
print(v)
print("unstruction suivante  produit matriciel de A et v ici v est une matrice colonne ")
print(np.dot(A,v))
print("unstruction suivante élève touts les élements de A au carré")
print(A**2)
print("unstruction suivante produit matriciel de A avec A")
print(np.dot(A,A))
print("unstruction suivante produit matriciel de A avec A")
print((A@A))
print("unstruction suivante produit matriciel de v et A ici v est une matrice ligne")
print(np.dot(v,A))
print("unstruction suivante")
print(A) 
print("unstruction suivante: transposée de A")
print(A.T)
print(A.transpose())
print("unstruction suivante: matrice diagoonale")
print(np.diag([1,3,5]))
print(np.zeros((2,3))) #matrice de 0  2 lignes 3 colonnes
print(np.ones((3,2)))  #matrice de 1  3 lignes 2 colonnes
print("unstruction suivante matrice identitée et matrice random")
print(np.eye(5,5)) # matrice identité
print(np.random.rand(2,4))
 
print("unstruction suivante exercice ")
matrice= np.array([[1,2,3],[1,-2,4]])
A=np.array([5,6,7])
print(matrice)
print(A)
print(matrice@A)
print(np.dot(matrice,A))

print("unstruction suivante graphe ")
x = np.linspace(0,1, 20)
print("valeurs de x :",x)
y = np.exp(-x)
print("valeur de y: ",y)
plt.figure()
plt.plot(x,y)
plt.show()

print("unstruction suivante nouveau graphe ")
plt.figure()
plt.plot(x,y, label='exp(-x)')
plt.plot(x,x, 'r *', label='bissectrice')
plt.title('titre de la figure')
plt.xlabel('axe x')
plt.ylabel('axe y')
plt.legend()
plt.show()

t = np.linspace(0,1,20)
y1 = np.cos(t)
y2 = np.sin(t)
plt.figure()
plt.subplot(3,2,1) # matrice 3lignes 2colonnes et la courbe dans la première case 
plt.plot(t,y1)
plt.subplot(3,2,5) # matrice 3lignes 2colonnes et la courbe dans la cinquième case
plt.plot(t,y2)
plt.show()

Npts = 100
x = np.random.rand(Npts, 1)
y = np.random.rand(Npts, 1)
plt.figure()
plt.title('Nuage de points')
plt.plot(x,y, '*')
plt.show()

Nbins = 10
plt.figure()
plt.hist(x, bins=Nbins)
plt.title('Histogramme de x')
plt.show()

plt.figure()
z = np.array([np.arange(0,10,0.1)]).T
plt.scatter(x,y, c=z)
plt.colorbar()
plt.show()

z = np.array([np.arange(0,10,0.1)]).T
print(x[0,0], y[0,0], z[0,0])


def g(x) :
    return 5*x**6 + 2*x-1
# Exercice : tracer g sur [-2,1]
print(op.fmin(g, -0.5))
print(op.fsolve(g, 0.5))
 
A = np.array([ [0,1,1] , [1,0,1], [1,1,0]])
B = la.inv(A)
print(A)
print(B)
print(A@B)

b = np.array([5,4,3])
x = la.solve(A,b)
print('x=',x)
print(A@x)
 
