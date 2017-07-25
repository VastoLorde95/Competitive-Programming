from math import factorial
MOD = (10**9)+7
def ncr(a,b):
	return (factorial(a)/(factorial(b)*factorial(a-b)))%MOD
n = input()
for i in xrange(n):
	x = input()
	print (x*ncr(x+x,x)/2)%MOD
