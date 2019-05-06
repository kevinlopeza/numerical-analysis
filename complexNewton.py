

def f(z):
	return z**3 - 2.0*z + 2.0

def df(z):
	return 3*z**2 - 2


p0 = 1 + 1j

for i in range(0, 10):
	p = p0 - f(p0)/df(p0)
	print(str(i) + "\t" + str(p) + "\n")
	if(abs(p - p0) < 10**-10):
		break
	p0 = p

print(f(0.8846461771193157+0.5897428050222056j))
