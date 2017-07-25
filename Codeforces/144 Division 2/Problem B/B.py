n = input()
mn = 10**18
for s in xrange(1, 163):
	d = s*s + 4*n
	if d >= 0:
		root = int(d**0.5)
		if (root+1)*(root+1) == d:
			root += 1
		elif (root-1)*(root-1) == d:
			root -= 1
		if root*root == d:
			if (-s+root)%2 == 0:
				a = (-s+root)/2
				b = (-s-root)/2
				if a > 0:
					tmp = str(a)
					sm = 0
					for c in tmp:
						sm += int(c)
					if sm == s:
						mn = min(mn, a)
				if b > 0:
					tmp = str(b)
					sm = 0
					for c in tmp:
						sm += int(c)
					if sm == s:
						mn = min(mn, b)
if mn == 10**18:
	print -1
else:
	print mn
