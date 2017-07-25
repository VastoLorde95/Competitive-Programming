from math import *
from fractions import *
from datetime import *

d = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11: 30, 12:31}

def solve():
	s = raw_input().split()
	x = int(s[0])
	if s[2] == "month":
		if x <= 29:
			print 12
		elif x == 30:
			print 11
		elif x == 31:
			print 7
	else:
		cnt = 0
		x -= 1
		for i in xrange(1,13):
			t = d[i]
			for j in xrange(1,t+1):
				if date(2016,i,j).weekday() == x:
					cnt += 1
		print cnt
	return

solve()
