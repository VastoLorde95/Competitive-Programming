from random import *
t = 100
N = 15
print t

g = open('ans.out','w')

for _ in xrange(t):
	n = randrange(1,N+1)	
	print n
	st = ''
	l = [randrange(10**9) for i in xrange(n)]
	s = []
	for i in xrange(1<<n):
		tmp = []
		for j in xrange(n):
			if (i&(1<<j)) > 0:
				tmp.append(l[j])
		s.append(sum(tmp))
	l.sort()
	s.reverse()
	for num in s:
		print num,
	print

	for num in l:
		st += str(num) + ' '
	g.write(st + '\n')
