from random import *

t = 100
n = 8
m = 10
print t
for _ in xrange(t):
	a, b = randrange(2,n+1), randrange(1,m+1)
	k = randrange(1,a+1)
	
	print a,b,k
	
	for i in xrange(k):
		print i+1,
	print
	for i in xrange(b):
		x, y = randrange(1,a+1), randrange(1,a+1)
		if x == y:
			if x == a:
				y = x-1
			else:
				y = x+1
		print x, y
