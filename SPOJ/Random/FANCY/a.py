d = {}
for i in xrange(1,31):
	d[i] = 1<<(i-1)
t = input()
for i in xrange(t):
	s = raw_input()
	p = s[0]
	count = 1
	ans = 1
	i = 1
	while i < len(s):
		if s[i] == p:
			count += 1
		else:
			ans *= d[count]
			count = 1
			p = s[i]
		i += 1
	ans *= d[count]
	print ans
