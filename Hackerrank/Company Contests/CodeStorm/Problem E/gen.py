from random import *
t = 10
N = 10000
dff = 20
M = N - dff
print t
for _  in xrange(t):
	n = randrange(dff+1, N+1)
	m = randrange(n-dff, n+1)
	l = sample(range(1,n+1), m)
	print n, m,
	for i in l:
		print i,
	print
