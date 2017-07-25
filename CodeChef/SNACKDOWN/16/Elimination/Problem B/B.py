from math import *
from fractions import *

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)
def solve():
	n, c = [int(x) for x in raw_input().split()]
	
	if n == 1:
		print 'Yes'
		return
	
	if (n*(n+1))/2 > c:
		print 'No'
		return
	
	m = (n * (n-1)) / 2
	
	g, a, b = egcd(n,m)
	
	if c % g != 0:
		print 'No'
		return
	
	if a == 0 or b == 0:
		print 'Yes'
		return
	
	u = m*c/(1.0*a)
	l = -n*c/(1.0*b)
	
	if int(a) > int(b):
		print 'Yes'
	else:
		print 'No'
	
t = input()
for _ in xrange(t):
	solve()
