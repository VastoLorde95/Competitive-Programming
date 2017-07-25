print 10,10
s = '.*.*.*.*.*'
s2 = '*.*.*.*.*.'
for _ in xrange(10):
	if _%2:
		print s
	else:
		print s2
