s = open('case.in', 'r').read()
cnt = 0
for j in xrange(0,386):
	if s[j] == 'l': cnt += 1
print cnt
