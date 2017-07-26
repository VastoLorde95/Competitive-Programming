f = open('result', 'r')

a = []
for line in f:
	l = line.split()
	if len(l) < 4: continue;
	a.append(l[-1])

s = 0
for x in a:
	s += float(x)
#	if float(x) > 0: s += 1.0
print s/len(a)
