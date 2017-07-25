d = {}
s = raw_input()
l = len(s)
for i in xrange(l+1):
	for j in xrange(26):
		t = s[:i] + chr(97+j) + s[i:]
		d[t] = 1
print len(d)
