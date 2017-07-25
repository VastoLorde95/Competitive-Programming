from itertools import permutations
st = map(int, raw_input().split())
n, m = st[0], st[1]
l = [0] * n
p = [1]
for i in xrange(n-1):
	p.append(p[-1]*2)
cnt = 0
first = 0
last = n-1
i = 2
while cnt < n:
	if m <= p[n-i]:
		l[first] = cnt+1
		first += 1
	else:
		l[last] = cnt+1
		last -= 1
		m -= p[n-i];
	#m -= p[n-i];
	#print m, p[n-i]	
	cnt += 1
	#print l
	i += 1
for i in l:
	print i,
