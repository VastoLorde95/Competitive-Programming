from math import *
from fractions import *

l = []

def solve():
	x = int(raw_input())
	
	n = 1
	while True:
		t1 = (n*n) - ((n*(n-1))/2)
		t2 = ((n-1)*n*(2*n-1))/6
		t2 -= (n*n*(n-1))/2
		
		if x-t2 < n*t1:
			break
		
		m = (x-t2)/t1
		if m*t1 == x-t2:
			l.append((n,m))
			if n != m:
				l.append((m,n))
		n += 1
	l.sort()
	print len(l)
	
	for pair in l:
		print pair[0], pair[1]
	
	return

solve()
