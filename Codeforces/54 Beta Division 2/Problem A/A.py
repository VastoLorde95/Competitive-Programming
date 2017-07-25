s = raw_input()
l = len(s)
if 'h' in s:
	i = s.index('h')
	s = s[i+1:]
	if 'e' in s:
		i = s.index('e')
		s = s[i+1:]
		if 'l' in s:
			i = s.index('l')
			s = s[i+1:]
			if 'l' in s:
				i = s.index('l')
				s = s[i+1:]
				if 'o' in s:
					print "YES"
				else:
					print "NO"
			else:
				print "NO"
		else:
			print "NO"
	else:
		print "NO"
else:
	print "NO"
