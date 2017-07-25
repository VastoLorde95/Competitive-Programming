a,b = [int(x) for x in raw_input().split()]
n = a-b
if n < 0:
	print 0
elif n == 0:
	print 'infinity'
else:
	i = 1
	count = 0
	while i*i <= n:
		if n%i == 0:
			if i > b:
				count += 1
			if  n/i > b:
				count += 1
		i += 1
	i -= 1
	if i*i == n and n%i == 0 and i > b:
		count -= 1
	#if n%i == 0 and i*i == n:
	#	count += 1
	print count
