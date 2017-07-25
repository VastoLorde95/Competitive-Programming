s = raw_input()
t = raw_input()
d1, d2 = {}, {}
for c in s:
	if c in d1:
		d1[c] += 1
	else:
		d1[c] = 1
for c in t:
	if c in d2:
		d2[c] += 1
	else:
		d2[c] = 1
flag = 0
for c in d2:
	if c not in d1:
		flag = 1
		print "need tree"
	if flag == 1:
		break
if flag == 0:
	if d1 == d2:
		print "array"
	else:
		s2 = ''
		i = 0
		j = 0
		while i < len(s) and j < len(t):
			if s[i] == t[j]:
				s2 += s[i]
				i += 1
				j += 1
			elif s[i] != t[j]:
				i += 1
		if s2 == t:
			print "automaton"
		else:
			for key in d1:
				if key in d2 and d1[key] < d2[key]:
					flag = 1
					print "need tree"
				if flag == 1:
					break
			if flag == 0:
				print "both"
		
	
