from random import randrange
a = 1<<62
b = 1<<5
print 20
for T in xrange(20):
	l = randrange(a, a+b+1)	
	r = randrange(a, a+b+1)	
	if l > r:
		t = l
		l = r
		r = t
	print l,r
