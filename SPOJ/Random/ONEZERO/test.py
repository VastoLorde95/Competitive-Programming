mx = 0
for i in xrange(1, 100):
	j = 1
	while True:
		num = i * j
		s = str(num)
		if s.count('1') + s.count('0') == len(s):
			mx = max(mx, j)
			break
		j += 1
print mx
