n = input()

if n <= 10:
	print n
else:
	cnt = 9
	le = len(str(n))
	i = 2
	while i <= le-1:
		cnt += ((81*((1<<(i-1))-1) + 9))
		i += 1
	
	d = {}
	
	for i in xrange(1,10):
		d[(int(str(i)*le))] = 1
	
	for i in xrange(1,10):
		for j in xrange(10):
			if i != j:
				mask = 0
				while mask < (1<<le-1):
					tmp = ""
					for k in xrange(le-1):
						if (mask&(1<<k)) > 0:
							tmp = str(i) + tmp
						else:
							tmp = str(j) + tmp
					tmp = str(i) + tmp
					d[(int(tmp))] = 1
					mask += 1
	
	for key in d:
		if key <= n:
			cnt += 1
	print cnt
