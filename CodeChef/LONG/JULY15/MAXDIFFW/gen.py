print 50
cnt = 1
for i in xrange(50):
	for j in xrange(50):
		if i == j: print 0,
		else:
			print cnt,
			cnt += 1
	print
