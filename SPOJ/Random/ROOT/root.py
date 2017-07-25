a,b,q,ind,res,res2 = 0,0,0,0,"",""
d = {}
for i in xrange(input()):
	a, b = [int(x) for x in raw_input().split()]
	d = {}
	if b == 0 :
		print 'Invalid Input!!!'
		continue
	q = a/b
	r = a%b
	ind = 0
	res = str(q) + '.'
	if r == 0:
		print res+'0'
		continue
	res2 = ''
	while True:
		if r != 0 and r not in d:
			d[r] = ind
			ind += 1
			r *= 10
			res2 += str(r/b)
			r = r%b
		elif r == 0:
			break
		else:
			res2 = res2[:d[r]] + '(' + res2[d[r]:] + ')'
			break
	print res + res2
