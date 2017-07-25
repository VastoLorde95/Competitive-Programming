from math import *
from fractions import *

dp = {}

dp[0] = 0

tot = 0
for i in xrange(1, 100001):
	x = str(i)
	if x == x[::-1]:
		tot += i
	dp[i] = tot

for _ in xrange(input()):
	l,r = [int(x) for x in raw_input().split()]
	print dp[r] - dp[l-1]
