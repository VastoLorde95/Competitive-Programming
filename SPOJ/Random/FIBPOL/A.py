for _ in xrange(input()):
	a = input()
	
	if a == 0:
		print 1
		continue
	
	a = a * (a * 5 + 2) + 1
	
	lo = 1
	hi = 300000000000000000
	
	while lo + 1 < hi:
		mid = (lo + hi) / 2
		
		if mid * mid <= a: lo = mid
		else: hi = mid
		
	if lo * lo == a:
		print 1
	else:
		print 0
