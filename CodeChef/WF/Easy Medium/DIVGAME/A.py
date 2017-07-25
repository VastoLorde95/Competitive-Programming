N = 100
l = [0] * N

for i in xrange(2, N):
	t = [l[i-1]]
	for j in xrange(2, i):
		if i % j == 0:
			t.append(l[i/j])
	
	j = 0
	while j in t:
		j += 1
	l[i] = j
	
for i in xrange(1, N):
	print i, l[i]
