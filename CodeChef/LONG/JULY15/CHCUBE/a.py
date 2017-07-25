def doit():
	c = raw_input().split()
	if c[0] == c[3] == c[5]:
		print "YES"
		return
	if c[0] == c[4] == c[3]:
		print "YES"
		return
	if c[0] == c[4] == c[2]:
		print "YES"
		return
	if c[0] == c[2] == c[5]:
		print "YES"
		return
		
	if c[1] == c[3] == c[5]:
		print "YES"
		return
	if c[1] == c[4] == c[3]:
		print "YES"
		return
	if c[1] == c[4] == c[2]:
		print "YES"
		return
	if c[1] == c[2] == c[5]:
		print "YES"
		return
	print "NO"
	return
for _ in xrange(input()):
	doit()
