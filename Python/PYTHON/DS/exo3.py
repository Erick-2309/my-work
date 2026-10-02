
import matplotlib.pyplot as plt
import numpy as np

A=1
a=0.1
ω=2*np.pi
t = np.linspace(0, 10, 10000)
y = A*np.exp(-a*t)*np.cos(ω*t)
x1=A*np.exp(-a*t)
x2=-A*np.exp(-a*t)
plt.plot(t, y)
plt.plot(t, x1, 'r--')
plt.plot(t, x2, 'r--')
plt.show()


# Nouvelle figure
a1 = 0.1
a2= 0.5
a3= 1.0

#plt.figure()
y1 = A*np.exp(-a1*t)*np.cos(ω*t)
y2 = A*np.exp(-a2*t)*np.cos(ω*t)
y3 = A*np.exp(-a3*t)*np.cos(ω*t)

plt.subplot(121)
plt.plot(t, y1, 'b--', label='a=0.1')
plt.title("Influence du coefficient a=(0.1, 0.5, 1.0)")
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude")

plt.plot(t, y2, 'g--', label='a=0.5')   
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude")

plt.plot(t, y3, 'y--', label='a=1.0')
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude") 

plt.legend()
plt.tight_layout()
plt.show()





# influence de φ (avec φ=0, π/4, π/2) tout en fixant α=0.2

A=1
ω=2*np.pi
φ1=0,
φ2=np.pi/4
φ3=np.pi/2
a = 0.2

t = np.linspace(0, 10, 10000)
y = A*np.exp(-a*t)*np.cos(ω*t)
plt.figure( figsize=(10, 5))
plt.plot(t, y,)

# influence de φ (avec φ=0, π/4, π/2) tout en fixant α=0.2

y1 = A*np.exp(-a*t)*np.cos(ω*t+φ1)
y2 = A*np.exp(-a*t)*np.cos(ω*t+φ2)
y3 = A*np.exp(-a*t)*np.cos(ω*t+φ3)
plt.plot(t, y1,'b--',label="φ=0")
plt.title("Influence du coefficient W ")
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude")

plt.plot(t, y2, 'g--',label="φ=π/4")   
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude")

plt.plot(t, y3, 'y--', label="φ=π/2")
plt.xlabel("Temps (s)")
plt.ylabel("Amplitude") 


plt.legend()
plt.tight_layout()
plt.show()