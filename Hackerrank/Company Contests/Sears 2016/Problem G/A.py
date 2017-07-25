from math import *
from fractions import *

f = {}
f[-1] = 0
f[0] = 1
f[1] = 1

for i in xrange(2, 30):
	f[i] = f[i-1] + f[i-2]
	
for i in xrange(0, 30):
	for j in xrange(i+1):
		for k in xrange(i+1):
			if j + k != i: continue
			
			num = f[j]*f[k] + f[j-1]*f[k-1]
			
			assert num == f[i]
