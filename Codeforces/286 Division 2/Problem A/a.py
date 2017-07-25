s = raw_input()
i = 0
j = len(s) - 1
flag = 0
while i < j:
	if s[i] != s[j] and flag == 0:
		a = s[:j+1] + s[i] + s[j+1:]
		b = s[:i] + s[j] + s[i:]
		if a == a[::-1]:
			print a
			flag = 1
			break
		elif b == b[::-1]:
			print b
			flag = 1
			break
		else:
			print "NA"
			flag = 1
			break
	i += 1
	j -= 1
if flag == 0:
	if s == s[::-1]:
		l = len(s)
		if l%2 == 0:
			s = s[:l/2] + 'a' + s[l/2:]
		else:
			c = s[l/2]
			s = s[:l/2] + c + s[l/2:]
		print s
	else:
		print "NA"
