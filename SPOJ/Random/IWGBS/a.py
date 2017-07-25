n = input()
if n == 0:
	print 0
elif n == 1:
	print 2
elif n == 2:
	print 3
else: 
	a = 2
	b = 3
	c = 0 
	for i in xrange(2,n+1):
		c = a+b
		a = b
		b = c
	print a
