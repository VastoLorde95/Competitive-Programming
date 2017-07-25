from math import *
from fractions import *

def C(n,k):
	return factorial(n)/(factorial(k)*factorial(n-k))

def solve():
	n,k = [int(x) for x in raw_input(). split()]
	
	if k == 1:
		print 0
		return
	
	cur = 0
	d = -1
	while cur < k and d < n:
		k -= cur
#		print "$",cur,d,k
		d += 1
		cur = C(n,d)
	
			
#	if cur > k:
#		print "#",cur,d,k
#		cur -= C(n,d)
#		print "#",cur,d,k
	
	num = 0
#	k -= cur
	cur = 0
	
#	print d, k, n
			
	for i in xrange(n):
#		print '#',n-i-1,d,num,k,cur
		if n-i-1 == 0:
			num |= 1
			break
		if d > n-i-1:
			num |= (1<<(n-i-1))
			d -= 1
		elif cur + C(n-i-1,d) < k:
			cur += C(n-i-1,d)
			num |= (1<<(n-i-1))
			d -= 1
#		print k, num, d, cur, n-i-1,d
		if d == 0:
			break
		
	print num
	
	return
print C(60,30) < (1<<63)
for _ in xrange(input()):
	solve()
