from random import *

def bitTwister(x, y):
  x ^= x >> 11
  x ^= (x << 7) & 2636928640
  x ^= (x << 15) & 4022730752
  x ^= (x >> 18)
  return (1812433253 * (x ^ (x >> 30)) + y) & 4294967295


N = randrange(1, 1000000)
a = [randrange(0, 1<<32) for i in xrange(N)]

x = a[0]
cnt = 0
for i in xrange(1, N):
	x = bitTwister(x, a[i])
	if x == 0:
		cnt += 1
print cnt
