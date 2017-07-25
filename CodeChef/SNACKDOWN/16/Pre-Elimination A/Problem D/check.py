from math import *
from fractions import *

mx = 0
for i in xrange(1, 1+10**5):
	cnt = 0
	for j in xrange(0,17):
		if (i&(1<<j)) > 0:
			cnt += 2*j
	mx = max(mx, cnt)
print mx
