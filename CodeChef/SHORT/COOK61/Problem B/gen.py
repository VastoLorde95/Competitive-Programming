for i in xrange(1,1025):
	ok = 0
	for j in xrange(1,1025):
		if (j^(j+1)) == i:
			ok = j
			break
	if ok > 0:
		print i,j
	else:
		print i
