s = raw_input()
t = raw_input()
l1, l2 = len(s), len(t)

c1, c2 = 0, 0

d = {}
ind = {}
i = 0

for c in t:
	if c not in d:
		d[c] = 1
	else:
		d[c] += 1
		
for c in s:
	if c in d and d[c] > 0:
		d[c] -= 1
		c1 += 1
		ind[i] = 1
	i += 1


i = 0
x = ''
for c in s:
	if i not in ind:
		if c.islower():
			x = c.upper()
		else:
			x = c.lower()
			
		if x in d and d[x] > 0:
			d[x] -= 1
			c2 += 1
	i += 1
	
print c1, c2
