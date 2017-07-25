for _ in xrange(input()):
	n = input()
	s = 1
	p = 4
	while s+p <= n:
		s += p
		p *= 4
	if s == n:
		print s
	else:
		diff = n-s
		if diff <= s+1:
			print diff
		else:
			diff -= (s+1)
			if diff%2 == 0:
				print s+1 + (3*(diff/2))
			else:
				print s+1 + (3*(diff+1)/2)-1
	
