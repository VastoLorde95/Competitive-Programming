from random import *

T = randrange(1,100)
print T

for t in xrange(T):
	n = 3
	print n
	for i in xrange(n):
		s = randrange(1,10)
		print s,
		for j in xrange(s):
			print randrange(-9,10),
		print
