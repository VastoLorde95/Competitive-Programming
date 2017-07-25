from math import *
from fractions import *

def solve(n):
	ans = 0
	for i in xrange(1, n+1):
		if gcd(i,n) == 1:
			ans += gcd(i-1, n)
	return ans

for i in xrange(1,20):
	s = 0
	
	for j in xrange(1, i+1):
		p = 1
		t = j
		while t > 0:
			p *= t % 10
			t /= 10
		
		s += solve(p)
	
	print i, s
