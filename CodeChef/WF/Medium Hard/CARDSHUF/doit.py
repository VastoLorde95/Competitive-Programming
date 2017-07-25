from math import log

def log2(n):
	return log(n) / log(2)

def T(n):
	if n <= 1:
		return 0
	return 2 * log2(n) + 2 * T(n/2)

for i in xrange(1, 30):
	print 1 << i, T(1 << i)
