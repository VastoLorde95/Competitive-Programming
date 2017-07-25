n = input()
a = [int(x) for x in raw_input().split()]

q = input()
for _ in xrange(q):
	qr = raw_input().split()
	for i in xrange(1, len(qr)):
		qr[i] = int(qr[i])

	x = qr[1]	
	if qr[0] == 'I':
		x -= 1
		a = a[:x] + [qr[2]] + a[x:]
	elif qr[0] == 'D':
		x -= 1
		a = a[:x] + a[x+1:]
	elif qr[0] == 'R':
		x -= 1
		a[x] = qr[2]
	else:
		x = qr[1] - 1
		y = qr[2] - 1

		mx = max(a[x:y+1])
		sm = 0
		
		for i in xrange(x,y+1):
			sm += a[i]
			if sm < 0:
				sm = 0
			else:
				mx = max(mx, sm)
		
		print mx
		
