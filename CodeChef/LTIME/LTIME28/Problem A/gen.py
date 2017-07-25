from random import *

t = 5
print t

for _ in xrange(t):
	n = randrange(2,11)
	print n, randrange(1,n), randrange(1,n), randrange(1,10)
	for _ in xrange(n):
		print randrange(1, 10), 
	print

