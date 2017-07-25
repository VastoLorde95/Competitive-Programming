for _ in xrange(input()):
	a = raw_input()
	b = raw_input()
	l = input()
	
	a = int(a, 7)
	b = int(b, 7)

	assert a % b == 0

	a /= b
	
	res = ''
	if a == 0:
		res = '0'
		print res
	else:
		while a > 0:
			res += str(a % 7)
			a /= 7
		
		res = res[:l][::-1]
		fres = []
		i = 0
		while i < l and res[i] == '0':
			i += 1
		
		if i < l:
			fres = res[i:]
		else:
			fres = '0'
		
		assert len(fres) <= l
		
		print fres
