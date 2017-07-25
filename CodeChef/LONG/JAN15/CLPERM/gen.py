from random import randrange
print 100
for i in xrange(100):
	n = randrange(1,500)
	k = randrange(1,n+1)
	d = {}
	print n,k
	j = 0
	while j < k:
		x = randrange(1,n+1)
		if x not in d:
			d[x] = 1
			print x,
			j += 1
	print
