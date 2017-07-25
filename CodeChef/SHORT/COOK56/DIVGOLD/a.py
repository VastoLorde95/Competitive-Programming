for _ in xrange(input()):
	n = input()
	s = raw_input()
	l = []
	l.append(s)
	for i in xrange(n):
		t = ""
		for j in xrange(n+1):
			if i > j:
				t = s[:j] + s[i] + s[j:i] + s[i+1:]
				l.append(t)
			elif i < j:
				t = s[:i] + s[i+1:j] + s[i] + s[j:]
				l.append(t)
	l.sort()
	print l[0]
