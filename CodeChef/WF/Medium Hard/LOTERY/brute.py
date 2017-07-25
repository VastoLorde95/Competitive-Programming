from math import factorial as f
from fractions import gcd

MOD = (10**9)+7

def F(n, k):
	return (f(n) / (f(k) * f(n-k))) * k

def solve(n, k):
	l = [F(n, i) for i in xrange(1, k+1)]
	return (reduce(lambda x, y: x * y / gcd(x,y), l)) % MOD

t = input()
n, k = [int(x) for x in raw_input().split()]
a, b, m = [int(x) for x in raw_input().split()]

c = [int(x) for x in raw_input().split()]
d = [int(x) for x in raw_input().split()]

ans = solve(n, k)
print ans

for i in xrange(t-1):
	n = 1 + (a * ans + c[i]) % m
	k = 1 + (b * ans + d[i]) % n
	
	ans = solve(n, k)
	print ans
