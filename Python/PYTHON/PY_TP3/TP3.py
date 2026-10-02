from math import sqrt
import csv
 

class Complexe():
     
     def __init__(self,re,im): 
         self.preelle = re 
         self.pimagin = im
     

     def re(self):
         return self.preelle
     
     def im(self):
         return self.pimagin
     
     def module(self):
         return sqrt(self.preelle**2 + self.pimagin**2)
     
     def __add__(self, self2):
         pr = self.preelle + self2.preelle 
         pi = self.pimagin + self2.pimagin 
         return Complexe(pr,pi)

     def __mult__(self, self2):
         pr = self.re*self2.re - self.im*self2.im 
         pi = self.re*self.im + self.im*self2.re 
         return Complexe(pr,pi)

     def __str__(self):
        return str(self.preelle)+' + '+str(self.pimagin)+'*i'
    
cplx1 = Complexe(2,5)
print(cplx1.preelle)
print(cplx1.re())
print(cplx1.im())

print(cplx1.module())
print(cplx1)
cplx2 = Complexe(3,4)
cplx = cplx1 + cplx2
print(cplx)
type(cplx)


#Un exemple de classe qui hérite d'une autre

class Polygone:
     def __init__(self, nbcotes):
         self.n = nbcotes
         self.cotes = [0 for i in range(nbcotes)]
         
class Triangle(Polygone): 
    def __init__(self):
        Polygone.__init__(self,3)
        
    def aire(self):
        a, b, c = self.cotes 
        s=(a+b+c)/2
        return(s*(s- a)*(s-b)*(s-c)) ** 0.5
    
    
    
poly = Polygone(5)
poly.cotes=[2,3,6,1,2]
print(poly.n)
tri = Triangle()
tri.cotes = [3,4,5]
print(tri.n)
print(tri.aire())
    


# Écriture dans un fichier

file = open('monfichier.txt', 'w')
for i in range(1,4):
    file.write('ligne Numero '+str(i)+'\n')
file.close()

fichier = open('monfichier.txt', 'r')
content = fichier.read()
print(content)
print(type(content))
fichier.close()

f = open('tableur.csv') 
lire = csv.reader(f) 
for l in lire :
    print(l)
print(type(l))
f.close()

print("instruction suivante")
f = open('tableur.csv') 
lire = csv.reader(f)
L = []
for l in lire :
    L.append(l)
f.close()
print(L)
    
    
    
    
    
    