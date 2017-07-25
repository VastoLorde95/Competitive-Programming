from math import *
from fractions import *

f = factorial

for _ in xrange(input()):
	n  = input()
	res = 0
	
	for i in xrange(n+1):
		res += (f(n) / f(i) / f(n-i)) % 3
	print res
