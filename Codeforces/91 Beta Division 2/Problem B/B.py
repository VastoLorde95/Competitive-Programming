s = raw_input()
r = ""
i = 0
while i < len(s) and s[i] == '0':
	i += 1
while i < len(s):
	r += s[i]
	i += 1
l = []
i = 0
for i in xrange(len(r)):
	tmp = ""
	for j in xrange(i, len(r)):	
		flag = 0
		for k in xrange(i, j+1):
			if r[k] == '4' or r[k] == '7':
				tmp += r[i]
			else:
				flag = 1
				break
		if flag == 0:
			l.append(tmp)
if len(l) == 0:
	print -1
else:
	d = {}
	for i in l:
		d[i] = r.count(i)
	mx = 0
	l = []
	for i in d:
		mx = max(mx, d[i])
	for i in d:
		if d[i] == mx:
			l.append(i)
	l.sort()
	print l[0]
