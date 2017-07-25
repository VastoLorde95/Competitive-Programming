def recur(p_c, i):
	if i >= l and p_c == '':
		return 0
	elif i >= l:
		return 1
	if (p_c,i) in d:
		return d[(p_c, i)]
	else:
		if p_c != '':
			if s[i] > p_c:
				d[(p_c,i)] = recur(s[i], i + 1) + recur(p_c, i + 1)
			else:
				d[(p_c, i)] = recur(p_c, i+1)
		else:
			d[(p_c,i)] = recur(s[i], i + 1) + recur('', i + 1)
	return d[(p_c, i)]
t = input()
l = 0
s = ''
d = {}
for i in range(t):
    d = {}
    s = raw_input()
    l = len(s)
    st = 'Case ' + str(i+1) + ':'
    print st,recur('', 0)
