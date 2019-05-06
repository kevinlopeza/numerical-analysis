import numpy as np
import matplotlib.pyplot as plt

a = 1703.28
b = 0.00169099
R = 461.495
P = 10000
T = 800

def g1(v):
	return P*v**2 - (P*b + R*T)*v + (a*b)/2

v = np.arange(-10.0, 10.0, 0.1)

#plt.plot(v, g1(v))
#plt.show()

def g2(v):
	return np.sqrt( (a*v - a*b + P*v**3)/( P*b + R*T ) )


#plt.plot(v, g2(v), 'bo', v, v, 'k')
#plt.show()

def g3(v):
	return ( ( (P*b + R*T)*v**2 - a*v + a*b)/P )**(1/3.0)

plt.plot(v, g3(v), 'bo', v, v, 'k')
plt.show()

print(g3(0.0823992))
