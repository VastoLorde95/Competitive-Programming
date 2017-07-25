n, m = [int(x) for x in raw_input().split()]
d = {}
for _ in xrange(n):
	s = raw_input()
	d[s] = 1;
for _ in xrange(m):
	flag = 0
	s = raw_input()
	l = len(s)
	for i in xrange(l):
		if flag == 1:
			break
		if s[i] == 'a':
			r = s[:i] + 'b' + s[i+1:]
			if r in d:
				print "YES"
				flag = 1
			else:
				r = s[:i] + 'c' + s[i+1:]
				if r in d:
					print "YES"
					flag = 1
		elif s[i] == 'b':
			r = s[:i] + 'a' + s[i+1:]
			if r in d:
				print "YES"
				flag = 1
			else:
				r = s[:i] + 'c' + s[i+1:]
				if r in d:
					print "YES"
					flag = 1
		else:
			r = s[:i] + 'a' + s[i+1:]
			if r in d:
				print "YES"
				flag = 1
			else:
				r = s[:i] + 'b' + s[i+1:]
				if r in d:
					print "YES"
					flag = 1
	if flag == 0:
		print "NO"
