from math import *
from fractions import *

L = 10

a = [1, 0]
b = [0, 1]

for i in xrange(2, L):
	a.append((i-1) * a[i-2] + a[i-1])
	b.append((i-1) * b[i-2] + b[i-1])

p = 1	
for i in xrange(L):
	if i > 0:
		p *= b[i]
	print a[i], b[i], p
	
