from math import *
from fractions import *

def solve():
	for _ in xrange(input()):
		n = input()
		lo = 1
		hi = 2000000000
		while lo+1 <= hi:
			mid = (lo+hi)/2
			val = ((mid*(mid-1))/2) + 1
			if val < n: lo = mid+1
			else: hi = mid
		print lo
			
	return

solve()
