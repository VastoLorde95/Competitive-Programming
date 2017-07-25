from math import *
from fractions import *

p = [1]
for i in xrange(1, 20001):
	p.append(p[i-1]*2)

d = [0 for i in xrange(10001)]

def add(x, y, a, b):
	num = x*b + y*a
	den = y*b
	return num, den

def solve():
	n = int(raw_input())
	
	t = n
	cnt = 0
	while t%2 == 0:
		t /= 2
		cnt += 1
	if t == 1:
		s = str(cnt)+'/1'
		print s
		return
	
	m, cur, X, pos = n, 1, 0, 0
	
	l = []
	
	Pnum, Pden = 0, 1
	
	ok = True
	start = 0
	while ok:
		cur *= 2
		pos += 1
		
		if cur >= n:
			cur -= n
			l.append(pos)
			if d[cur] == 0:
				d[cur] = pos
			else:
				pt = d[cur]
				length = len(l)
				for i in xrange(length):
					val = l[i]
					if val <= pt:
						Pnum, Pden = add(Pnum, Pden, m*val, p[val])
					else:
						X = pos - l[i-1]
						start = i
						ok = False
						break
	i = l[-1]
	Tnum, Tden = 0, p[i]
	Snum, Sden = 0, p[i]
	length = len(l)
	
	for j in xrange(start, length):
		Tnum += l[j]*p[i-l[j]]
		Snum += p[i-l[j]]
	
	g1 = gcd(Tnum, Tden)
	Tnum /= g1
	Tden /= g1
	
	g2 = gcd(Snum, Sden)
	Snum /= g2
	Sden /= g2
	
	tmp = p[X]
	tnum, tden = tmp, tmp-1
	
	Tnum *= tnum
	Tden *= tden
	
	g1 = gcd(Tnum, Tden)
	Tnum /= g1
	Tden /= g1
	
	Snum *= X
	Snum *= tmp*tmp
	Sden *= (tmp-1)*(tmp-1)
	Sden *= tmp
	
	g2 = gcd(Snum, Sden)
	Snum /= g2
	Sden /= g2
	
	Anum, Aden = add(Tnum, Tden, Snum, Sden)
	Anum *= m
	
	g = gcd(Anum, Aden)
	Anum /= g
	Aden /= g
	
	g = gcd(Pnum, Pden)
	Pnum /= g
	Pden /= g
	
	Anum, Aden = add(Anum, Aden, Pnum, Pden)
	
	g = gcd(Anum, Aden)
	Anum /= g
	Aden /= g
	
	s = str(Anum)+ '/' + str(Aden)
	print s

	return

solve()
