from math import factorial
f = factorial

def C(n,k):
	return f(n)/(f(k)*f(n-k))

for K in xrange(2,101):
	for i in xrange(1,10**5):
		v = C(i+K-1,i-1)
		if v > 10**5:
			print i, K
			break
