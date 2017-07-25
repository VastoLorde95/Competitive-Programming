from math import *
f = factorial

def C(n,k):
	return f(n)/(f(k)*f(n-k))

for i in xrange(1,20):
	s = 0
	for j in xrange(0,i+1):
		s += C(i,j)
		print s,
	print
