t = input()
flag = 1
for T in xrange(t):
	a,d,r = [int(x) for x in raw_input().split()]
	n, m = [int(x) for x in raw_input().split()]
	if flag:
		l = [a%m]
		flag2 = 0
		for i in xrange(100):
			flag2 = 1 - flag2
			if flag2:
				l.append((l[-1]+d)%m)
			else:
				l.append((l[-1]*r)%m)
		flag = 0
	print l[n-1]
