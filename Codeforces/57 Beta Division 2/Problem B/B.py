a = raw_input().replace('-','').replace(';','').replace('_','').lower()
b = raw_input().replace('-','').replace(';','').replace('_','').lower()
c = raw_input().replace('-','').replace(';','').replace('_','').lower()

l = [a+b+c, a+c+b, c+a+b, c+b+a, b+c+a, b+a+c]

#print a
#print b
#print c

for i in xrange(input()):
	s = raw_input().replace('-','').replace(';','').replace('_','').lower()
	
	#print s
	flag = 1
	for w in l:
		if w == s:
			print "ACC"
			flag = 0
			break
	if flag == 1:	
		print "WA"
