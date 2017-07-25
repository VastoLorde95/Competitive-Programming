from math import *
from fractions import *

def solve():
	n = int(open('china.in', 'r').read())
	f = open('china.out', 'w')
	if n%2 == 1:
		f.write(str(n/2))
	else:
		k = n/2
		k -= 1
		if k%2 == 1:
			f.write(str(k))
		else:
			f.write(str(k-1))
		
	return

solve()
