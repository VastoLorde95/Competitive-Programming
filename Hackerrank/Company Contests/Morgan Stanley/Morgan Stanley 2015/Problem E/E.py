from math import *
from fractions import *

def ways(N):
	if(N == 1):
		return 1
	
	tot = 0
	
	for i in xrange(1,N+1):
		if i == 1 or i == N:
			tot += ways(N-1)
			tot += 2
		else:
			tot += ways(i-1)
			tot += ways(N-i)
			tot += 1
	return tot
	
for _ in xrange(1,11):
	print ways(_)
	
