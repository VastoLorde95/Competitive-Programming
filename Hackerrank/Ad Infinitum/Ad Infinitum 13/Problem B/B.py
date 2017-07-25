from math import *
from fractions import *

def get(a, b, c, d):
	return abs(gcd(c-a,d-b))+1

def solve():
	x1, y1, x2, y2, x3, y3 = [int(x) for x in raw_input().split()]
	

	A = abs(((x1*(y2-y3)) + (x2*(y3-y1)) + (x3*(y1-y2))))+2

	b1 = get(x1,y1,x2,y2);
	b2 = get(x1,y1,x3,y3);
	b3 = get(x2,y2,x3,y3);
	
	b = b1+b2+b3-3;

	i = A - b
	print i/2
	
	return
t = input()
for _ in xrange(t):
	solve()
