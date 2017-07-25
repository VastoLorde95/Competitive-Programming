from math import *
from fractions import *

def solve():
	n, k, b = [int(x) for x in raw_input().split()]
	
	v = (b*(b+1))/2
	if n < v:
		print -1
		return
	
	if n == v:
		for i in xrange(1, b): print i,
		print b
		return
	
	tmp = (k*(k+1))/2
	tmp -= ((k-b)*(k-b+1))/2;
	
	if tmp < n:
		print -1
		return
	
#	x = b+1
#	while x <= k:
#		up = ((x*(x+1))/2) - (((x-b)*(x-b+1))/2)
#		down = up - b
#		if down <= n and n <= up:
#			diff = up - n
#			a = []
#			for i in xrange(b):
#				if i < diff:
#					a.append(x-b+i)
#				else:
#					a.append(x-b+i+1)
#					
#			for i in xrange(b-1):
#				print a[i],
#			print a[-1]
#			return
#		x += 1
			
	
	lo = b
	hi = k + 1
	while lo + 1 < hi:
		x = (lo + hi) / 2
		up = ((x*(x+1))/2) - (((x-b)*(x-b+1))/2)
		
#		print lo, x, hi, up, up-b, n
		
		if up < n: lo = x + 1
		elif up - n > b: hi = x
		else:
			a = []
			for i in xrange(b):
				a.append(x - b + 1 + i)
			
			diff = up - n
			
			for i in xrange(diff):
				a[i] -= 1
			
			for i in xrange(b-1):
				print a[i],
			print a[-1]
			return
			
	x = lo
	up = ((x*(x+1))/2) - (((x-b)*(x-b+1))/2)
	if up - b >= 0 and up - b <= n and n <= up and x <= k:
		a = []
		for i in xrange(b):
			a.append(x - b + 1 + i)
		
		diff = up - n
		
		for i in xrange(diff):
			a[i] -= 1
		
		for i in xrange(b-1):
			print a[i],
		print a[-1]
		return
		
	print -1
	
	return

for _ in xrange(input()):
	solve()
