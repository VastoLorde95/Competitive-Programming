from math import *
from fractions import *

def solve():
	n = input()
	a = input()
	b = input()
	c = input()
	
	res = 0
	
	if a > n and b > n:
		print res
		return
	
	if a <= b-c:
		res += n/a
		n %= a
		
		if a + n >= b and a+n-b+c >= a:
			res += 1
		print res
	elif b <= n:
		up = ((n-b)/(b-c) + 1)*(b-c)
		res += up / (b-c)
		
		n -= up
		
		a = min(a,b)
		
		res += n / a
		print res
	else:
		print n/a
	return

solve()
