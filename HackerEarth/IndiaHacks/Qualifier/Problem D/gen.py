from random import *

N = 100
n = randrange(2,N+1)
m = randrange(1,1+(n*(n+1)))
print n,m
for i in xrange(m):
	a = randrange(1,n+1)
	b = randrange(1,n+1)
	print a, b
