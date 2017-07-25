n = input()
a = []
b = []
pts_a, pts_b = 0, 0
last = -1
for i in xrange(n):
	x = input()
	if x > 0:
		a.append(x)
		pts_a += x
		last = 0
	else:
		b.append(-x)
		pts_b += -x
		last = 1
#print a, b
if pts_a > pts_b:
	print 'first'
elif pts_a < pts_b:
	print 'second'
else:
	if a > b:
		print 'first'
	elif a < b:
		print 'second'
	else:
		if last == 0:
			print 'first'
		else:
			print 'second'
	
