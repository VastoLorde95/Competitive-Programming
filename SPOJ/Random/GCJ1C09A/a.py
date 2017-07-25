t = input()
for T in xrange(1,t+1):
	d = {}
	s = raw_input()
	l = len(s)
	if l == 1:
		print 'Case #'+str(T)+':', 1
		continue
	d[s[0]] = 1
	flag = False
	a = 2
	for ch in s:
		if ch in d:
			continue
		if not flag:
			d[ch] = 0
			flag = True
			continue
		d[ch] = a
		a += 1
	ans = 0
	for ch in s:
		ans *= a
		ans += d[ch]
	print 'Case #'+str(T)+':', ans
