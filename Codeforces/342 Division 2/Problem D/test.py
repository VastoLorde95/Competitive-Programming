from math import *
from fractions import *

def solve():
	for i in xrange(1,10000):
		j = int(str(i)[::-1])
		print i, j, i+j
	return

solve()
