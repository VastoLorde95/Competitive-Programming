from math import *
from fractions import *

def solve():
	n = input()
	v1 = n*n*n
	n = max(0, n-2)
	v2 = n*n*n
	print v1-v2
	return

for _ in xrange(input()):
	solve()
