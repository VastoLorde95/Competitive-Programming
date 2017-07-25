s = raw_input()
d = {}
for c in s:
	if c != '{' and c != '}' and c != ',' and c != ' ':
		d[c] = 1
print len(d)

