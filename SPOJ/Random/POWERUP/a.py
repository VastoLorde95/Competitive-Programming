import sys
def exp(a,b,p):
	res = 1
	while b:
		if b&1:
			res = (res*a)%p
		a = (a*a)%p
		b >>= 1
	return res
MOD = (10**9)+7
a,b,c = map(int, sys.stdin.readline().split())#[int(x) for x in raw_input().split()]
while a != -1:
	if a%MOD:
		print exp(a,exp(b,c,MOD-1),MOD)
	else:
		if b == 0 and c != 0:
			print 1
		else:
			print 0
	
	a,b,c = map(int, sys.stdin.readline().split())#[int(x) for x in raw_input().split()]
