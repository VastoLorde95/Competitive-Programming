p,q = [int(x) for x in raw_input().split()]
f = (p*1.0)/q
if f > 0.5:
	print "Palindromic tree is better than splay tree"
	print f
else:
	
	c1, c2 = 1, 0
	i = 2
	while c2 <= c1*f:
		s = str(i)
		if s == s[::-1]:
			c1 += 1
		j = 2
		tmp = i
		ok = True
		while j <= tmp:
			if tmp%j == 0:
				ok = False
				break
			j += 1
		if ok:
			c2 += 1
		i += 1
	print i-1
		
		
