from fractions import gcd
n = input()
mx = 0

if n == 1:
	print 1
elif n == 2:
	print 2
else:
	if n%2 == 1:
		print n*(n-1)*(n-2)
	else:
		if n%3 == 0:
			print (n-1)*(n-2)*(n-3)
		else:
			print n*(n-1)*(n-3)
