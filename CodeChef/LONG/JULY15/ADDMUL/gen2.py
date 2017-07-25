from random import *
n = 10
m = 5
up = 10
lo = 1
print n, m
for i in xrange(n):
	print randrange(lo, up+1),
print
for i in xrange(m-1):
	t = randrange(1,5)
	l = randrange(1,n+1)
	r = randrange(1,n+1)
	if l > r:
		l,r = r,l
	if t <= 3:
		print t,l,r,randrange(lo,up+1)
	else:
		print t,l,r
print 4, 1, n
