s = raw_input()
ss = s
if "AB" in s:
	i = s.index("AB")
	s = s[:i] + s[i+2:]
	if "BA" in s:
		print "YES"
	else:
		if "BA" in ss:
			i = ss.index("BA")
			ss = ss[:i] + ss[i+2:]
			print s
			if "AB" in ss:
				print "YES"
			else:
				print "NO"
		else:
			print "NO"
else:
	print "NO"
