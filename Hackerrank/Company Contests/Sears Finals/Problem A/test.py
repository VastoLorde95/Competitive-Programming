from math import *
from fractions import *

def solve(n):
	ans = 1
	while n > 0:
		ans *= n
		
		s = str(ans)
		j = len(s)-1
		cnt = 0
		while j >= 0 and s[j] == '0':
			j -= 1
			cnt += 1
		
		print n, ans, cnt
		n -= 2
	print ans
	cnt = 0
	while ans > 0 and ans % 10 == 0:
		cnt += 1
		ans /= 10
	
	return cnt

print solve(input())
