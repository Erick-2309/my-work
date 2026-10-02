
"""
Created on Tue May  4 12:49:05 2021
@author: rjennane
"""
import matplotlib.pyplot as plt
import numpy as np

##--------------------------------------------------------------------
# Exo 1
# y = cos(x) sur [0, 10pi].
x = np.linspace(0, 10 * np.pi, 1000)
y1 = np.cos(x)
plt.plot(x, y1)
plt.show()

##--------------------------------------------------------------------
# Exo 2
# cos(x) et exp(-x/10)cos(x) sur [0, 10pi].
x = np.linspace(0, 10 * np.pi, 1000)
y1 = np.cos(x)
y2 = np.exp(-x/10) * y1
plt.plot(x, y1)
plt.plot(x, y2)
plt.title("Cos et Exponentielle amortie")
plt.xlabel("x")
plt.ylabel("y = f(x)")
plt.show()

##--------------------------------------------------------------------
# Exo 3
# # Lemniscate de Bernoulli
t = np.linspace(0, 2 * np.pi, 100)
x = np.sin(t) / (1 + np.cos(t) ** 2)
y = x * np.cos(t)
plt.plot(x,y)
plt.show()

##--------------------------------------------------------------------
# Spirale d'Archimède
t = np.linspace(0, 10 * np.pi, 300)
x = t * np.cos(t)
y = t * np.sin(t)
plt.plot(x, y)
plt.show()

##--------------------------------------------------------------------
# Courbe du coeur
t = np.linspace(0, 2 * np.pi, 100)
x = 16 * np.sin(t) ** 3
y = 13*np.cos(t) - 5*np.cos(2*t) - 2*np.cos(3*t) - np.cos(4*t)
plt.plot(x, y)
plt.show()

##--------------------------------------------------------------------
# Cyclo-harmoniques
p = 8
q = 3
t = np.linspace(0, 2 * q * np.pi, 400)
tmp = 1 + np.cos(p / q * t)
x = tmp * np.cos(t)
y = tmp * np.sin(t)
plt.plot(x, y)
plt.show()
