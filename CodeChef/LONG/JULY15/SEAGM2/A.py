from decimal import *
getcontext().prec = 30
for _ in xrange(input()):
	n, m = [int(x) for x in raw_input().split()]
	p = []
	for i in xrange(n):
		p.append([Decimal(x) for x in raw_input().split()])
	x = Decimal(1)
	y = Decimal(1)
	
	for i in xrange(m):
		x *= p[0][i]
	y -= x
	for i in xrange(1,n):
		tmp = Decimal(1)
		for j in xrange(m):
			tmp *= p[i][j]
		y -= tmp
	
	if y == Decimal(1):
		print '%.6f' % float(x)
		continue
	
	res = x / (Decimal(1) - y)
	print '%.6f' % float(res)
