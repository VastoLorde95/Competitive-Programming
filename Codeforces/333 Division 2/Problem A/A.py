from math import *
from fractions import *

def solve():
	n, bx = [int(x) for x in raw_input().split()]
	s1 = [int(x) for x in raw_input().split()]
	m, by = [int(x) for x in raw_input().split()]
	s2 = [int(x) for x in raw_input().split()]
	
	num1 = 0
	num2 = 0
	
	p1 = 1
	i = n-1
	while i >= 0:
		num1 += p1*s1[i]
		p1 *= bx
		i-=1
	
	j = m-1
	p2 = 1
	while j >= 0:
		num2 += p2*s2[j]
		p2 *= by
		j-=1	 
	
	if num1 < num2:
		print '<'
	elif num1 > num2:
		print '>'
	else:
		print '='
	
	return

solve()
