t = input()
for j in xrange(t):
	n = input()
	l = [int(x) for x in raw_input().split()]
	flag = 0
	for i in xrange(1,n):
		if l[i] < l[i-1]:
			flag = 1
			break
		else:
			l[i] -= l[i-1]
			l[i-1] = 0
	if flag == 1:
		print 'NO'
	elif l[-1] > 0:
		print 'NO'
	elif l[-1] == 0:
		print 'YES'		
