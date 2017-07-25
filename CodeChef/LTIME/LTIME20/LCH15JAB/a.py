t = input()
for _ in xrange(t):
	d = {}
	s = raw_input()
	l = len(s)
	if l%2 == 1:
		print 'NO'
		continue
	for c in s:
		if c in d: 
			d[c] += 1
		else:
			d[c] = 1
	flag = 0
	for key in d:
		if d[key] == l/2:
			flag = 1
			print 'YES'
			break
	if flag == 0:
		print 'NO'
