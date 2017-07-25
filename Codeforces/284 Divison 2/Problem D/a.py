n = 31623
primes = [2]
for i in xrange(3, n+1):
	flag = 0
	for j in primes:
		if i%j == 0:
			flag = 1
			break
	if flag == 0:
		primes.append(i)
print len(primes)
