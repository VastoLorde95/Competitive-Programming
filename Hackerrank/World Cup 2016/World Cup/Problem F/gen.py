from math import *
from fractions import *
from random import *

n = 1000000000
q = 200000

print n, q
for _ in xrange(q):
	t = randrange(1,4)
	l,r,c = randrange(1,n+1), randrange(1,n+1), 1000000000
	if t < 3:
		print t,l,r,c
	else:
		print t,l,r
#print 3, 1, 1000000000
