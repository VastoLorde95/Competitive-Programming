from math import factorial as f
def g(n):
	return f(n) / (f(n/2) * f(n - (n/2)))

vals = []
for i in xrange(2, 64+1):
	vals.append(g(i))

print vals
