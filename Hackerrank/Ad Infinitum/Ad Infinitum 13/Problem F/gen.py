from random import *

up = 1000

n = 5
m = 5
print n, m
for i in xrange(n):
	print randrange(1,100),
print
for i in xrange(m):
	print randrange(-up,up)
