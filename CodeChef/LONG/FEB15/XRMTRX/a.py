for _ in xrange(input()):
	l, r = [int(x) for x in raw_input().split()]
	for i in xrange (l,r+1):
		print 'row',i,'\t',
		for j in xrange(l,r+1):
			print i^j,'\t',
		print
	print
