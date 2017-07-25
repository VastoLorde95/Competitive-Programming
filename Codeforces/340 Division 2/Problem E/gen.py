from random import *

N, M, K = randrange(1,10), randrange(1,10000), randrange(20)

print N, M, K
for i in xrange(N):
	print randrange(K+1),
print
for i in xrange(M):
	l = randrange(1, N+1)
	r = randrange(l, N+1);
	print l, r
