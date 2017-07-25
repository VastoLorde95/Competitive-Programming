from random import *
def f(x,y,a,b):
	return (1.0 - (x**a)) * (1.0 - (y**b))

for i in xrange(100):
	a = random()
	b = random()
	if a < b: a, b = b, a
	x = randrange(2,20)
	y = randrange(1,20)
	print f(a,b,x,y) <= f(a,b,x-1,y+1)
	print f(a,b,x,y), f(a,b,x-1,y+1), a, b, x, y

