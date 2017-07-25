from random import *
t = 5
n = 8
print t
for _ in xrange(t):
	x = randrange(1,n+1)
	print x
	for _ in xrange(x):
		print randrange(-50,51), randrange(-50,51)
