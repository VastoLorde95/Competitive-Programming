from itertools import permutations
st = map(int, raw_input().split())
n, m = st[0], st[1]
l = range(1, n+1)
p = list(permutations(l))
for x in p:
	print x,
	s = 0
	for i in xrange(len(x)):
		mi = 1000
		for j in xrange(i, len(x)):
			mi = min(mi, x[j])
			s += mi
	print s
