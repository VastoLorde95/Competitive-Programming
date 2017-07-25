n = input()
s = ""
for i in xrange(1, n+1):
	x = i%4
	if x == 1:
		s += 'a'
	elif x == 2:
		s += 'b'
	elif x == 3:
		s += 'c'
	else:
		s += 'd'
print s
