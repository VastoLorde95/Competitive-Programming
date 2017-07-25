from math import *
from fractions import *
from decimal import *

def solve():
	getcontext().prec = 100
	x, y, z = [Decimal(x) for x in raw_input().split()]

	i = 1000

	if x >= 1 and y >= 1 and z >= 1:
		v1 = z*Decimal(log(y)) + Decimal(log(Decimal(log(x))))
		v2 = y*Decimal(log(z)) + Decimal(log(Decimal(log(x))))
		v3 = log(Decimal(y*z*Decimal(log(x))))
	
		v5 = z*Decimal(log(x)) + Decimal(log(Decimal(log(y))))
		v6 = x*Decimal(log(z)) + Decimal(log(Decimal(log(y))))
		v7 = log(Decimal(x*z*Decimal(log(y))))
	
		v9 = y*Decimal(log(x)) + Decimal(log(Decimal(log(z))))
		v10 = x*Decimal(log(y)) + Decimal(log(Decimal(log(z))))
		v11 = log(Decimal(x*y*Decimal(log(z))))
		
		l = [(v1,-1), (v2,-2), (v3,-3), (v5,-5), (v6,-6), (v7,-7), (v9,-9), (v10,-10), (v11,-11)]
		l.sort()
	
		i = -l[-1][1]
	
	else:
		v1 = x**(y**z)
		v2 = x**(z**y)
		v3 = x**(y*z)
	
		v5 = y**(x**z)
		v6 = y**(z**x)
		v7 = y**(x*z)
	
		v9 = z**(x**y)
		v10 = z**(y**x)
		v11 = z**(x*y)
	
		l = [(v1,-1), (v2,-2), (v3,-3), (v5,-5), (v6,-6), (v7,-7), (v9,-9), (v10,-10), (v11,-11)]
		l.sort()
	
		i = -l[-1][1]
	
	if i == 1:
		print "x^y^z"
	elif i == 2:
		print "x^z^y"
	elif i == 3:
		print "(x^y)^z"
	elif i == 5:
		print "y^x^z"
	elif i == 6:
		print "y^z^x"
	elif i == 7:
		print "(y^x)^z"
	elif i == 9:
		print "z^x^y"
	elif i == 10:
		print "z^y^x"
	elif i == 11:
		print "(z^x)^y"
	
	return

solve()
