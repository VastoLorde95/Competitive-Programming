N = 59
l = []

for _ in xrange(N):
	x, y = [int(x) for x in raw_input().split()]
	for j in xrange(y):
		l.append(x)

print len(l)
for x in l:
	print x, 
